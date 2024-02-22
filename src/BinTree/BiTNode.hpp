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

#ifdef __MYDSA__RBTREE_IMPL__
enum class RBcolor { red, black };

template <typename T>
using RBPtr = BiTNode<T>*;

template <typename T>
using CRBPtr = const BiTNode<T>*;

template <typename T>
using RBNode = BiTNode<T>;

template <typename T>
constexpr bool IsBlack(const CRBPtr<T> node) {
  return node == nullptr || node->color() == RBcolor::black;
}

template <typename T>
constexpr bool IsRed(const CRBPtr<T> node) {
  return !IsBlack(node);
}
#endif

template <typename T>
constexpr inline int stature(const CBPtr<T> node_ptr) {
#ifdef __MYDSA__RBTREE_IMPL__
  // 外部节点黑高度为0
  return node_ptr != nullptr ? node_ptr->Height() : 0;
#else
  return node_ptr != nullptr ? node_ptr->Height() : -1;
#endif
}

template <typename T>
constexpr inline bool HeightUpdated(const CBPtr<T> node_ptr) {
  return node_ptr->Height() ==
         1 + std::max(stature(node_ptr->lChild()), stature(node_ptr->rChild()));
}

template <typename T>
constexpr inline bool HasLChild(const CBPtr<T> node_ptr) {
  return node_ptr->lChild() != nullptr;
}

template <typename T>
constexpr inline bool HasRChild(const CBPtr<T> node_ptr) {
  return node_ptr->rChild() != nullptr;
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
  return node_ptr->Parent() == nullptr;
}

template <typename T>
constexpr inline bool IsRChild(const CBPtr<T> node_ptr) {
  return !IsRoot(node_ptr) && node_ptr->Parent()->rChild() == node_ptr;
}

template <typename T>
constexpr inline bool IsLChild(const CBPtr<T> node_ptr) {
  return !IsRoot(node_ptr) && node_ptr->Parent()->lChild() == node_ptr;
}

template <typename T>
constexpr inline BPtr<T> Sibling(const CBPtr<T> node_ptr) {
  return IsLChild(node_ptr) ? node_ptr->Parent()->rChild()
                            : node_ptr->Parent()->lChild();
}

template <typename T>
class BinTree;

template <typename T>
class BST;

template <typename T>
class RBTree;

template <typename T>
class Splay;

template <typename T>
struct BiTNode {
  T data;
#ifdef MY_TEST
  //~BiTNode() { std::cout << "\n**destroy BiTNode**\n"; }
#endif

  friend class BinTree<T>;
  friend class BST<T>;
  friend class RBTree<T>;
  friend class Splay<T>;
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
  const BPtr<T> lChild() const { return this->left; }
  const BPtr<T> rChild() const { return this->right; }
  const BPtr<T> Parent() const { return this->parent; }
  BPtr<T>& lChild() { return this->left; }
  BPtr<T>& rChild() { return this->right; }
  BPtr<T>& Parent() { return this->parent; }

  int Height() const { return this->height; }
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
#ifdef __MYDSA__RBTREE_IMPL__
  RBcolor color() const { return this->_color; }
#endif
 protected:
  BPtr<T> parent = nullptr;
  BPtr<T> left = nullptr, right = nullptr;
  int height = 0;
#ifdef __MYDSA__RBTREE_IMPL__
  RBcolor _color = RBcolor::red;
#endif
};

}  // namespace CYT_DSA

#include "BiTNode_impl.hpp"
