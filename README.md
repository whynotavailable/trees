# Trees

Exploration in trees.

They all use keys in the form of an `int`.

Here is the list.

* [B+](./src/btree.h) (WIP)

## Test Nonsense

```cmake
# gcc
target_compile_options(tests PRIVATE -fprofile-arcs -ftest-coverage)

# clang
target_compile_options(tests PRIVATE -fprofile-instr-generate -fcoverage-mapping)

# gcc
target_link_options(tests PRIVATE -fprofile-arcs -ftest-coverage)

# clang
target_link_options(tests PRIVATE -fprofile-instr-generate -fcoverage-mapping)
```
