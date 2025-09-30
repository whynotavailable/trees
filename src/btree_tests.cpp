#include "btree.h"
#include <gtest/gtest.h>
#include <iostream>

class T {
public:
    T() {
        std::cout << "init\n";
    }

    ~T() {
        std::cout << "destroy\n";
    }

    operator bool() const {
        return true;
    }
};

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
    if (T t; t) {
        std::cout << "yolo\n";
    }
    BTree::BTree h;
    h.Add(2);
    std::cout << "hi\n";
    {
        T b;
        std::cout << "hhh\n";
    }
}
