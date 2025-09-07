#pragma once

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

    // TODO: Need to test, but it should clear everything down the tree.
    ~BTreeNode() {
        for (auto it = this->children.begin(); it != this->children.end();
             it++) {
            delete *it;
            *it = 0;
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
