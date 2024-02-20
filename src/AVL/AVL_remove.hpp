#pragma once

namespace CYT_DSA {
template <typename T>
bool AVL<T>::remove(const T& e) {
  BPtr<T>& x = this->search(e);//不加引用的后果很严重
  if (x == nullptr) return false;
  this->erase(this->_hot, x);
  this->_size--;

  for (BPtr<T> g = this->_hot; g != nullptr; g = g->parent) {
    if (AVLBalanced(g) == false) {
      BPtr<T>& p = BinTree<T>::FromParentTo(g);
      p = this->rotateAt(tallerChild(tallerChild(g)));
      g = p;
    }
    this->updateHeight(g);
  }

  return true;
}

}  // namespace CYT_DSA