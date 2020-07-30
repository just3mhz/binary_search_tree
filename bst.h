#pragma once

#include <iostream>
#include <memory>

#include "node.h"

template <typename TKey, typename TValue>
class TBinarySearchTree {
public:
    using TNode_ = std::unique_ptr<TNode<TKey, TValue>>;

    void Insert(const TKey &key, const TValue &value) {
        TNode_ &found_node = FindNodeWithKey(root_, key);
        if ( found_node != nullptr ) {
            throw std::invalid_argument("Node with this key already exist");
        }
        found_node = std::make_unique<TNode<TKey, TValue>>(key, value);
    }

    void Remove(const TKey &key) {
        TNode_ &found_node = FindNodeWithKey(root_, key);
        if ( found_node == nullptr ) {
            throw std::invalid_argument("Key not found");
        }
        if ( found_node->Left() == nullptr && found_node->Right() == nullptr) {
            found_node = nullptr;
        }
        else if ( found_node->Left() == nullptr ) {
            found_node = std::move(found_node->Right());
        }
        else if ( found_node->Right() == nullptr ) {
            found_node = std::move(found_node->Left());
        } else {
            TNode_ &swap_node = MostRight(found_node->Left());
            found_node->Key() = std::move(swap_node->Key());
            found_node->Value() = std::move(swap_node->Value());
            swap_node = nullptr;
        }
    }
    
    const TValue& Find(const TKey & key) const {
        TNode_ &found_node = FindNodeWithKey(root_, key);
        if ( found_node == nullptr ) {
            throw std::invalid_argument("Key not found");
        }
        return found_node->Value();
    }

    TValue& Find(const TKey & key) {
        TNode_ &found_node = FindNodeWithKey(root_, key);
        if ( found_node == nullptr ) {
            throw std::invalid_argument("Key not found");
        }
        return found_node->Value();
    }

    template <typename K, typename V>
    friend std::ostream& operator << (std::ostream &os, const TBinarySearchTree<K,V> &bst);
private:
    std::ostream& Print(std::ostream &os, const TNode_ &root) const {
        if ( root == nullptr ) {
            return os;
        }
        Print(os, root->Left());
        os << "(" << root->Key() << ", " 
           << root->Value() << ")";
        Print(os, root->Right());
        return os;
    }

    TNode_& FindNodeWithKey(TNode_ &node, const TKey &key) {
        if ( node == nullptr || node->Key() == key ) {
            return node;
        }
        if ( node->Key() > key ) {
            return FindNodeWithKey(node->Left(), key);
        } else {
            return FindNodeWithKey(node->Right(), key);
        }
    }

    TNode_& MostRight(TNode_ &node) {
        if ( node->Right() == nullptr ) {
            return node;
        }
        return MostRight(node->Right());
    }

    TNode_ root_ = nullptr;
    size_t size_ = 0;
};
    
template <typename K, typename V>
std::ostream& operator << (std::ostream &os, const TBinarySearchTree<K,V> &bst) {
    os << "[ ";
    bst.Print(os, bst.root_);
    os << " ]";
    return os;
}
