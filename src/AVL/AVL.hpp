#pragma once

#include "BST/BST.hpp"

namespace CYT_DSA {

template <typename T>
constexpr bool Balanced(const CBPtr<T> x) {
  return stature(x->left) == stature(x->right);
}

template <typename T>
constexpr int BalFac(const CBPtr<T> x) {
  return stature(x->left) - stature(x->right);
}

template <typename T>
constexpr bool AVLBalanced(const CBPtr<T> x) {
  return BalFac(x) < 2 && BalFac(x) > -2;
}

template <typename T>
constexpr BPtr<T> tallerChild(const CBPtr<T> x) {
  return stature(x->left) > stature(x->right)   ? x->left
         : stature(x->left) < stature(x->right) ? x->right
         : IsLChild(x)                          ? x->left
                                                : x->right;
}

template <typename T>
class AVL : public BST<T> {
 public:
  virtual BPtr<T> insert(const T& e);  // 锟斤拷锟斤拷
  virtual bool remove(const T& e);     // 删锟斤拷
 protected:
};

}  // namespace CYT_DSA

#include "AVL_impl.hpp"