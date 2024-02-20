#pragma once

namespace CYT_DSA {
template <typename T>
int BiTNode<T>::size() const{
  int s = 1;
  if (left != nullptr) s += left->size();
  if (right != nullptr) s += right->size();
  return s;
}

}