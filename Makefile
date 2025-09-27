export CXX=/usr/bin/clang++

run: compile
	ls

test: compile
	build/tests
	rm -rf test_output
	mkdir -p test_output
	llvm-profdata merge -sparse default.profraw -o test_output/default.profdata
	llvm-cov export build/tests -instr-profile=test_output/default.profdata --format=lcov >test_output/coverage.info
	genhtml test_output/coverage.info --output-directory test_output/html

compile: build
	cmake --build build

build:
	cmake -G Ninja -S . -B build

clean:
	rm -rf build
