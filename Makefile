run: compile
	ls

test: compile
	build/tests

compile: build
	cmake --build build

build:
	cmake -G Ninja -S . -B build

# To force a new one
cm:
	cmake -G Ninja -S . -B build
