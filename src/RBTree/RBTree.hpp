#pragma once
#define __MYDSA__RBTREE_IMPL__

#include "BST/BST.hpp"

namespace CYT_DSA {
template <typename T>
constexpr bool BlackHeightUpdated(const CRBPtr<T> node) {
  return (stature(node->lChild()) == stature(node->rChild())) &&
         node->Height() == IsBlack(node) + stature(node->lChild());
}

template <typename T>
class RBTree : public BST<T> {
 public:
  RBPtr<T> insert(const T& e) override;
  bool remove(const T& e) override;
  using BST<T>::search;

 protected:
  void solveDoubleRed(BinNodePosi<T> x);    // 双红修正
  void solveDoubleBlack(BinNodePosi<T> x);  // 双黑修正
  using BST<T>::erase;
  rank updateHeight(BinNodePosi<T> x) override {
    return x->height =
               IsBlack(x) + std::max(stature(x->left), stature(x->right));
  };  // 重写高度，黑高度
};

}  // namespace CYT_DSA

#include "RBTree_impl.hpp"