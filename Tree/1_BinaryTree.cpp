#include <iostream>

template <typename Type>
class Binary_node
{
protected:
    Type element;
    Binary_node *left_tree;
    Binary_node *right_tree;

public:
    // Değişkini mainden alan kurucu fonksiyon
    Binary_node(Type const &);

    // Elementin içerisindeki veriyi gönderen fonksiyon
    Type retrieve() const;
    // Sol çocuk düğümün adresini veren fonksiyon
    Binary_node *left() const;
    // Sağ çocuk düğümün adresini veren fonksiyon
    Binary_node *right() const;

    bool empty() const;
    bool is_leaf() const;
    // Toplam düğüm sayısını veren fonksiyon
    int size() const;
    int height() const;
    void clear();
};

template <typename Type>
Binary_node<Type>::Binary_node(Type const &obj)
{
    element = obj;
    left_tree = nullptr;
    right_tree = nullptr;
}
template <typename Type>
Type Binary_node<Type>::retrieve() const
{
    return element;
}
template <typename Type>
Binary_node<Type> *Binary_node<Type>::left() const
{
    return left_tree;
}
template <typename Type>
Binary_node<Type> *Binary_node<Type>::right() const
{
    return right_tree;
}
template <typename Type>
bool Binary_node<Type>::empty() const
{
    return (this == nullptr);
}
template <typename Type>
bool Binary_node<Type>::is_leaf() const
{
    return !empty() && left()->empty() && right()->empty();
}
template <typename Type>
int Binary_node<Type>::size() const
{
    return empty() ? 0 : 1 + left()->size() + right()->size();
}
template <typename Type>
int Binary_node<Type>::height() const
{
    return empty() ? -1 : 1 + std::max(left()->height, right()->height());
}