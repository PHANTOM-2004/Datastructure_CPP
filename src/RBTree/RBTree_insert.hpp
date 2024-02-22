#pragma once

namespace CYT_DSA {
template <typename T>
RBPtr<T> RBTree<T>::insert(const T& e) {
  RBPtr<T> &s = this->search(e);
  if (s != nullptr) return s;  // exists, no need to insert
  s = new RBNode<T>(e, this->_hot, nullptr, nullptr, 0);
  this->_size++;

  const auto res = s;
  solveDoubleRed(s);
  return res;
}

}  // namespace CYT_DSA