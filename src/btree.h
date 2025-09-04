#pragma once

#include <vector>

enum BTreeStatus {
    Ok,
    OverCapacity,
    Error,
};

struct TreeConfig {
    int maxSize; // key num limit
    bool uniqueVals;
};

template <typename T>
class BTree;

template <typename T>
class BTreeNode {
public:
    bool isLeaf;
    std::vector<T> keys;

    // Probably could be a pointer but I don't care.
    struct TreeConfig config;

    // This should only be set if it's not a leaf
    std::vector<BTreeNode<T> *> children;

    // This should only be set if it's a leaf
    BTreeNode<T> *next;

    BTreeNode<T>(struct TreeConfig config, bool isLeaf) {
        this->isLeaf = isLeaf;
        this->config = config;
    }

    BTreeStatus Add(T val) {
        if (this->isLeaf) {
            if (this->keys.size() >= this->config.maxSize) {
                return BTreeStatus::OverCapacity; // TODO: make these enums
            }

            // Slow, but by design.
            // It's arguable that a raw array may be faster, but that's got it's
            // own problems.
            for (auto it = this->keys.begin(); it != this->keys.end(); ++it) {
                if (val < *it) {
                    this->keys.insert(it, val);
                    return BTreeStatus::Ok;
                }
            }
            this->keys.insert(this->keys.end(), val);
        }

        return BTreeStatus::Ok;
    }
};

template <typename T>
class BTree {
public:
    BTreeNode<T> *root;
    struct TreeConfig config;

    BTree(int maxSize) {
        this->config.maxSize = maxSize;
        this->config.uniqueVals = false;
        this->root = new BTreeNode<T>(this->config, true);
    };

    // Will return non zero if a failure.
    // 1 -> key already exists in a unique only tree
    BTreeStatus Add(T val) {
        auto code = this->root->Add(val);
        if (code == BTreeStatus::OverCapacity) {
            auto newRoot = new BTreeNode<T>(this->config, false);
            newRoot->children.push_back(this->root);
            this->root = newRoot;

            code = BTreeStatus::Ok; // we fixed it.
        }

        return code;
    }
};
