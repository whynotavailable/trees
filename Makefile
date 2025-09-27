export CXX=/usr/bin/clang++

run: compile
	ls

test: compile
	build/tests
	rm -rf test_output
	mkdir -p test_output
	llvm-profdata merge -sparse default.profraw -o test_output/default.profdata
	llvm-cov report build/tests -instr-profile=test_output/default.profdata \
		--ignore-filename-regex ".*tests\.cpp" \
		--show-branch-summary=false \
		--show-functions=false \
		--show-region-summary=false

cover_report: compile
	build/tests
	rm -rf test_output
	mkdir -p test_output
	llvm-profdata merge -sparse default.profraw -o test_output/default.profdata
	llvm-cov export build/tests -instr-profile=test_output/default.profdata --format=lcov --ignore-filename-regex ".*tests\.cpp" >test_output/coverage.info
	genhtml test_output/coverage.info --output-directory test_output/html

compile: build
	cmake --build build

build:
	cmake -G Ninja -S . -B build

clean:
	rm -rf build
