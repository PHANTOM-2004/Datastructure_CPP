#pragma once
//#define __SPLAY__INSERT__DEBUG__
#ifdef __SPLAY__INSERT__DEBUG__
#include "../TestCommon/Test_BinTree.hpp"
#endif

namespace CYT_DSA {
template <typename T>
BPtr<T> Splay<T>::insert(const T& e) {
  if (this->_root == nullptr) {
    this->_root = new BiTNode<T>(e);
    this->_size++;
    return this->_root;
  }
  BPtr<T> t = search(e);
#ifdef __SPLAY__INSERT__DEBUG__
  std::cout << "\nAfter search\n";
  tools::printBT(this);
#endif
  if (t->data == e) return t;  // 已经存在

  if (t->data < e) {  // 应当t在e的左侧
    this->_root = new BiTNode<T>(e, nullptr, t, t->right);
    t->parent = this->_root;
    if (t->right != nullptr) {
      t->right->parent = this->_root;
      t->right = nullptr;//这里很重要 切断t联系
    }
  } else {
    this->_root = new BiTNode<T>(e, nullptr, t->left, t);
    t->parent = this->_root;
    if (t->left != nullptr) {
      t->left->parent = this->_root;
      t->left = nullptr;
    }
  }
  this->_size++;
  this->updateHeightAbove(t);
  return this->_root;
}

}  // namespace CYT_DSA