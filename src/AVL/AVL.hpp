#pragma once

#include "BST/BST.hpp"

namespace CYT_DSA {

template <typename T>
constexpr bool Balanced(const CBPtr<T> x) {
  return stature(x->lChild()) == stature(x->rChild());
}

template <typename T>
constexpr int BalFac(const CBPtr<T> x) {
  return stature(x->lChild()) - stature(x->rChild());
}

template <typename T>
constexpr bool AVLBalanced(const CBPtr<T> x) {
  return BalFac(x) < 2 && BalFac(x) > -2;
}

template <typename T>
constexpr BPtr<T> tallerChild(const CBPtr<T> x) {
  return stature(x->lChild()) > stature(x->rChild())   ? x->lChild()
         : stature(x->lChild()) < stature(x->rChild()) ? x->rChild()
         : IsLChild(x)                                 ? x->lChild()
                                                       : x->rChild();
}

template <typename T>
class AVL : public BST<T> {
 public:
  BPtr<T> insert(const T& e) override;
  bool remove(const T& e) override;

 protected:
};

}  // namespace CYT_DSA

#include "AVL_impl.hpp"