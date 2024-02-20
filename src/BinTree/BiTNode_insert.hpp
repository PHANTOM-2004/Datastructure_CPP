#pragma once

namespace CYT_DSA {
template <typename T>
BPtr<T> BiTNode<T>::insertAsL(const T& e) {
  return left = new BiTNode(e, this);
}

template <typename T>
BPtr<T> BiTNode<T>::insertAsR(const T& e) {
  return right = new BiTNode(e, this);
}

}  // namespace CYT_DSA