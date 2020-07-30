#pragma once

#include <iostream>
#include <memory>

template <typename TKey, typename TValue>
class TNode {
public:
    TNode(const TKey &key, const TValue &value) : key_(key), value_(value) {
        /* Empty */
    }

    const std::shared_ptr<TNode>& Left() const {
        return left_;
    }

    const std::shared_ptr<TNode>& Right() const {
        return right_;
    }

    const TKey& Key() const {
        return key_;
    }

    const TValue& Value() const {
        return value_;
    }

    std::shared_ptr<TNode>& Left() {
        return left_;
    }

    std::shared_ptr<TNode>& Right() {
        return right_;
    }

    TKey& Key() {
        return key_;
    }

    TValue& Value() {
        return value_;
    }

private:
    TKey key_;
    TValue value_;
    std::shared_ptr<TNode> left_ = nullptr;
    std::shared_ptr<TNode> right_ = nullptr;
};
