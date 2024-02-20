#pragma once

namespace CYT_DSA {
template <typename T>
BPtr<T>& Splay<T>::search(const T& e) {
  BPtr<T>& p = BST<T>::search(e);
  //注意这里的语义约定，如果找不到那么就让_hot作为根节点
  this->_root = splay(p == nullptr ? this->_hot : p);
  return this->_root;
}

}  // namespace CYT_DSA