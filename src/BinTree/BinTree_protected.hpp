#pragma once
#include <utility>

namespace CYT_DSA {
template <typename T>
int BinTree<T>::updateHeight(BPtr<T> x) {
  return x->height = 1 + std::max(stature(x->left), stature(x->right));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BPtr<T> x) {
  while (x != nullptr) {
    updateHeight(x);
    x = x->parent;
  }
}


}  // namespace CYT_DSA