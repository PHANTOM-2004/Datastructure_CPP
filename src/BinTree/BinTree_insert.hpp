#pragma once

namespace CYT_DSA {

template <typename T>
BPtr<T> BinTree<T>::insert(const T& e) {
  _size = 1;
  return _root = new BiTNode<T>(e);
}

template <typename T>
BPtr<T> BinTree<T>::insert(const T& e, BPtr<T> x) {
  _size++;
  x->insertAsL(e);
  updateHeightAbove(x);
  return x->left;
}

template <typename T>
BPtr<T> BinTree<T>::insert(BPtr<T> x, const T& e) {
  _size++;
  x->insertAsR(e);
  updateHeightAbove(x);
  return x->right;
}

template<typename T>//接入左子树,并将S置空
BPtr<T> BinTree<T>::attach(BinTree<T>*& S, BPtr<T> x) {
  x->left = S->root();
  if (x->left != nullptr) x->left->parent = x;
  _size += S->size();
  updateHeightAbove(x);
  //释放资源 并置空
  S->_root = nullptr;
  delete S;
  S = nullptr;
  return x->left;
}

template <typename T>
BPtr<T> BinTree<T>::attach(BPtr<T> x, BinTree<T>*& S) {
  x->right = S->root();
  if (x->right != nullptr) x->right->parent = x;
  _size += S->size();
  updateHeightAbove(x);
  // 释放资源 并置空
  S->_root = nullptr;
  delete S;
  S = nullptr;
  return x->right;
}

}  // namespace CYT_DSA