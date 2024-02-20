#pragma once
#include <algorithm>

namespace CYT_DSA {
template <typename T>
struct BiTNode;

template <typename T>
using BPtr = BiTNode<T>*;

template <typename T>
using CBPtr = const BiTNode<T>*;

template <typename T>
using BinNodePosi = BiTNode<T>*;

template <typename T>
using BinNode = BiTNode<T>;

// red black树的时候这里定义不太一样

template <typename T>
constexpr inline int stature(const CBPtr<T> node_ptr) {
  return node_ptr != nullptr ? node_ptr->height : -1;
}

template <typename T>
constexpr inline bool HeightUpdated(const CBPtr<T> node_ptr) {
  return node_ptr->height ==
         1 + std::max(stature(node_ptr->left), stature(node_ptr->right));
}

template <typename T>
constexpr inline bool HasLChild(const CBPtr<T> node_ptr) {
  return node_ptr->left != nullptr;
}

template <typename T>
constexpr inline bool HasRChild(const CBPtr<T> node_ptr) {
  return node_ptr->right != nullptr;
}

template <typename T>
constexpr inline bool HasChild(const CBPtr<T> node_ptr) {
  return HasLChild(node_ptr) || HasRChild(node_ptr);
}

template <typename T>
constexpr inline bool HasBothChild(const CBPtr<T> node_ptr) {
  return HasLChild(node_ptr) && HasRChild(node_ptr);
}

template <typename T>
constexpr inline bool IsRoot(const CBPtr<T> node_ptr) {
  return node_ptr->parent == nullptr;
}

template <typename T>
constexpr inline bool IsRChild(const CBPtr<T> node_ptr) {
  return !IsRoot(node_ptr) && node_ptr->parent->right == node_ptr;
}

template <typename T>
constexpr inline bool IsLChild(const CBPtr<T> node_ptr) {
  return !IsRoot(node_ptr) && node_ptr->parent->left == node_ptr;
}

template <typename T>
struct BiTNode {
  T data;
  BPtr<T> parent = nullptr;
  BPtr<T> left = nullptr, right = nullptr;
  int height = 0;
#ifdef MY_TEST
  //~BiTNode() { std::cout << "\n**destroy BiTNode**\n"; }
#endif

  /*构造函数*/
  BiTNode() = default;
  BiTNode(const T& e, const BPtr<T> parent = nullptr,
          const BPtr<T> left = nullptr, const BPtr<T> right = nullptr,
          const int height = 0)
      : data(e), parent(parent), left(left), right(right), height(height) {}
  /*操作*/
  int size() const;
  BPtr<T> insertAsL(const T&);
  BPtr<T> insertAsR(const T&);
  BPtr<T> succ() const;
  BPtr<T> zig();
  BPtr<T> zag();

  template <typename func_type>
  void level_traverse(func_type&);

  template <typename func_type>
  void in_traverse(func_type&);

  template <typename func_type>
  void pre_traverse(func_type&);

  template <typename func_type>
  void post_traverse(func_type&);

  /*operator*/
  bool operator<(BiTNode const& b) const { return data < b.data; }
  bool operator<=(BiTNode const& b) const { return data <= b.data; }
  bool operator==(BiTNode const& b) const { return data == b.data; }
  bool operator!=(BiTNode const& b) const { return data != b.data; }
  bool operator>(BiTNode const& b) const { return data > b.data; }
  bool operator>=(BiTNode const& b) const { return data >= b.data; }
};

}  // namespace CYT_DSA

#include "BiTNode_impl.hpp"
