#pragma once

// TODO: Explore smart pointers and move semantics with them.

#include <vector>
namespace BTree {

enum BTreeStatus {
    Ok,
    OverCapacity,
    UndefinedError,
};

struct BTreeConfig {
    int maxKeys;
};

class BTreeNode {
private:
    BTreeConfig config;
    std::vector<int> keys;
    std::vector<BTreeNode *> children;

public:
    int depth; // This works in reverse, so a leaf will be 0

    BTreeNode(BTreeConfig config, int depth) {
        this->config = config;
        this->depth = depth;
    }

    ~BTreeNode() {
        for (auto node : this->children) {
            delete node;
        }

        this->children.clear();
    }

    BTreeStatus Add(int key) {
        return BTreeStatus::Ok;
    }
};

class BTree {
private:
    BTreeConfig config;

public:
    BTreeNode *root = 0;

    BTree() {
        config.maxKeys = 4;
        this->root = new BTreeNode(this->config, 0);
    }

    ~BTree() {
        if (this->root != 0) {
            delete this->root;
            this->root = 0;
        }
    }

    BTree(BTreeConfig config) {
        this->config = config;
    }

    BTreeStatus Add(int key) {
        return BTreeStatus::Ok;
    }

    BTreeNode NewNode(BTreeConfig config, int depth) {
        return BTreeNode(config, depth);
    }
};

}; // namespace BTree
