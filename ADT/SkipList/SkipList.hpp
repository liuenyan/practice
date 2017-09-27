#ifndef SKIPLIST_HPP_INCLUDED
#define SKIPLIST_HPP_INCLUDED

#include "SkipListNode.hpp"
#include <cassert>
#include <memory>
#include <new>
#include <random>

namespace sl {
template <typename KeyType, typename ValueType> class SkipList {
public:
    SkipList(int max_height = 16);
    ~SkipList();
    bool insert(KeyType* key, ValueType* value);
    bool remove(KeyType* Key);
    void print();
    const ValueType* find(const KeyType* key) const;

private:
    int random_height();
    bool is_tail(SkipListNode<KeyType, ValueType>* p) const
    {
        return p == tail_;
    };
    int max_height_;
    SkipListNode<KeyType, ValueType>* head_;
    SkipListNode<KeyType, ValueType>* tail_;
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist;
};

template <typename KeyType, typename ValueType>
SkipList<KeyType, ValueType>::SkipList(int max_height)
    : max_height_(max_height)
    , head_(0)
    , tail_(0)
    , engine(time(0))
    , dist(1, max_height)
{
    try {
        head_ = new SkipListNode<KeyType, ValueType>(0, 0, max_height);
        tail_ = new SkipListNode<KeyType, ValueType>(0, 0, 1);
    } catch (std::bad_alloc&) {
        delete head_;
        delete tail_;
        throw;
    }

    for (int i = 0; i < head_->getHeight(); i++) {
        head_->nexts_[i] = tail_;
    }
}

template <typename KeyType, typename ValueType>
SkipList<KeyType, ValueType>::~SkipList()
{
    SkipListNode<KeyType, ValueType>* p = head_;
    SkipListNode<KeyType, ValueType>* temp = NULL;
    while (p) {
        temp = p->nexts_[0];
        delete p;
        p = temp;
    }
}

template <typename KeyType, typename ValueType>
bool SkipList<KeyType, ValueType>::insert(KeyType* key, ValueType* value)
{
    std::unique_ptr<SkipListNode<KeyType, ValueType>* []> prevs(
        new SkipListNode<KeyType, ValueType>*[max_height_]);

    int lvl = max_height_ - 1;
    SkipListNode<KeyType, ValueType>* p = head_;
    while (lvl >= 0) {
        if (is_tail(p->nexts_[lvl])) {
            prevs[lvl--] = p;
        } else {
            KeyType* next_key = p->nexts_[lvl]->key_;
            if (*next_key == *key) {
                break;
            } else if (*next_key < *key) {
                p = p->nexts_[lvl];
            } else {
                prevs[lvl--] = p;
            }
        }
    }

    // key not exsit
    if (lvl >= 0) {
        return false;
    }

    int new_height = random_height();
    assert(new_height <= max_height_);
    auto new_node
        = new SkipListNode<KeyType, ValueType>(key, value, new_height);
    for (int i = 0; i < new_height; i++) {
        new_node->nexts_[i] = prevs[i]->nexts_[i];
        prevs[i]->nexts_[i] = new_node;
    }
    return true;
}

template <typename KeyType, typename ValueType>
bool SkipList<KeyType, ValueType>::remove(KeyType* key)
{
    std::unique_ptr<SkipListNode<KeyType, ValueType>* []> prevs(
        new SkipListNode<KeyType, ValueType>*[max_height_]);
    int lvl = max_height_ - 1;
    SkipListNode<KeyType, ValueType>* p = head_;

    while (lvl >= 0) {
        if (is_tail(p->nexts_[lvl])) {
            prevs[lvl--] = p;
        } else {
            KeyType* next_key = p->nexts_[lvl]->key_;
            if (*next_key < *key) {
                p = p->nexts_[lvl];
            } else {
                prevs[lvl--] = p;
            }
        }
    }

    SkipListNode<KeyType, ValueType>* delete_node = prevs[0]->nexts_[0];
    if (is_tail(delete_node) || *(delete_node->key_) != *key) {
        return false;
    }
    for (int i = 0; i < delete_node->getHeight(); ++i) {
        prevs[i]->nexts_[i] = delete_node->nexts_[i];
    }
    delete delete_node;
    return true;
}

template <typename KeyType, typename ValueType>
const ValueType* SkipList<KeyType, ValueType>::find(const KeyType* key) const
{
    SkipListNode<KeyType, ValueType>* p = head_;
    int lvl = max_height_ - 1;

    while (lvl >= 0) {
        if (is_tail(p->nexts_[lvl])) {
            lvl--;
        } else {
            if (*p->nexts_[lvl]->key_ == *key) {
                return p->nexts_[lvl]->value_;
            } else if (*p->nexts_[lvl]->key_ < *key) {
                p = p->nexts_[lvl];
            } else {
                lvl--;
            }
        }
    }
    return NULL;
}

template <typename KeyType, typename ValueType>
int SkipList<KeyType, ValueType>::random_height()
{
    return dist(engine);
}

template <typename KeyType, typename ValueType>
void SkipList<KeyType, ValueType>::print()
{
    for (auto p = head_->nexts_[0]; !is_tail(p); p = p->nexts_[0]) {
        for (int i = 0; i < p->getHeight(); i++) {
            printf("%2d ", *(p->getKey()));
        }
        printf("\n");
    }
}

}; // namespace sl
#endif
