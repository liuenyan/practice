#ifndef SKIPLISTNODE_HPP_INCLUDED
#define SKIPLISTNODE_HPP_INCLUDED

namespace sl {

// SkipList 模板前置声明
template <typename KeyType, typename ValueType> class SkipList;

// SkipListNode 类模板定义
template <typename KeyType, typename ValueType> class SkipListNode {
public:
    friend class SkipList<KeyType, ValueType>;
    SkipListNode(KeyType* key, ValueType* value, int height)
        : key_(key)
        , value_(value)
        , height_(height)
        , nexts_(0)
    {
        nexts_ = new SkipListNode<KeyType, ValueType>*[height]();
    };
    ~SkipListNode()
    {
        delete key_;
        delete value_;
        delete[] nexts_;
    };

    const KeyType* getKey() const { return key_; };
    const ValueType* getValue() const { return value_; };
    int getHeight() const { return height_; };
    void setKey(const KeyType* key) { key_ = key; };
    void setValue(const ValueType* value) { value_ = value; };
    void setHeight(int height) { height_ = height; };

private:
    KeyType* key_;
    ValueType* value_;
    int height_;
    SkipListNode<KeyType, ValueType>** nexts_;
};

}; // namespace sl
#endif
