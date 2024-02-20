#pragma once

namespace CYT_DSA {

template <typename T>
BPtr<T>& BST<T>::search(const T& e) {
  /*hot之中会一直存储着v的父节点*/
  if (this->_root == nullptr || this->_root->data == e) {
    _hot = nullptr;
    return this->_root;
  }
  _hot = this->_root;
  while (true) {
    auto& v = e < _hot->data ? _hot->left : _hot->right;
    if (v == nullptr || v->data == e) return v;
    _hot = v;
  }
}

}  // namespace CYT_DSA