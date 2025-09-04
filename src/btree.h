#pragma once

namespace BTree {

enum BTreeStatus {
    Ok,
    UndefinedError,
};

struct BTreeConfig {
    int maxKeys;
};

class BTreeNode {
private:
    BTreeConfig config;
};

class BTree {
private:
    BTreeConfig config;

public:
    BTree() {
        config.maxKeys = 4;
    }

    BTree(BTreeConfig config) {
        this->config = config;
    }

    BTreeStatus Add(int key) {
        return BTreeStatus::Ok;
    }
};

}; // namespace BTree
