#include "btree.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("B+ simple", "[BTree]") {
    BTree<int> hi(3);

    REQUIRE(hi.Add(2) == BTreeStatus::Ok);
    REQUIRE(hi.Add(12) == BTreeStatus::Ok);
    REQUIRE(hi.Add(4) == BTreeStatus::Ok);

    REQUIRE(hi.root->isLeaf);
}

TEST_CASE("B+ rebalance", "[BTree]") {
    BTree<int> hi(3);

    REQUIRE(hi.Add(2) == BTreeStatus::Ok);
    REQUIRE(hi.Add(12) == BTreeStatus::Ok);
    REQUIRE(hi.Add(4) == BTreeStatus::Ok);
    REQUIRE(hi.Add(6) == BTreeStatus::Error);

    REQUIRE_FALSE(hi.root->isLeaf);
}
