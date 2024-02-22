#pragma once

namespace CYT_DSA {

template <typename T>
static int remove_subtree(BPtr<T> x) {
  if (x == nullptr) return 0;
  int res = 1 + remove_subtree(x->lChild()) + remove_subtree(x->rChild());
  delete x;
  return res;
}

template<typename T>
int BinTree<T>::remove(BPtr<T> x) {
  FromParentTo(x) = nullptr;
  updateHeightAbove(x->parent);

  const auto sizedec = remove_subtree(x);
  _size -= sizedec;
  return sizedec;
}


template <typename T>
BinTree<T>* BinTree<T>::secede(BPtr<T> cur_root) {
  FromParentTo(cur_root) = nullptr;

  updateHeightAbove(cur_root->parent);

  auto Tree = new BinTree;
  Tree->_root = cur_root;
  Tree->_root->parent = nullptr;
  Tree->_size = Tree->root()->size();
  this->_size -= Tree->_size;
  return Tree;
}

}