#pragma once

namespace CYT_DSA {
template <typename T>
BPtr<T> BST<T>::insert(const T& e) {
  auto& x = search(e);
  if (x == nullptr) {
    x = new BiTNode<T>(e, _hot);
    this->_size++;
    this->updateHeightAbove(x);
  }
  return x;
}
}  // namespace CYT_DSA