#pragma once

namespace CYT_DSA {

template <typename T>
BPtr<T> AVL<T>::insert(const T& e) {
  BPtr<T> &pos = this->search(e);
  if (pos != nullptr) return pos;
  BPtr<T> new_node = (pos = new BiTNode<T>(e, this->_hot));
  this->_size++;

  for (BPtr<T> g = this->_hot; g != nullptr; g = g->Parent()) {
    if (AVLBalanced(g) == false) {
      BPtr<T> &p = this->FromParentTo(g);//这里不能分开写，毕竟这里的FromParent不是宏
      p = this->rotateAt(tallerChild(tallerChild(g)));
      break;
    } else
      this->updateHeight(g);
  }
  return new_node;
}

}  // namespace CYT_DSA