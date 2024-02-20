#pragma once

namespace CYT_DSA {
template <typename T>
void Quadlist<T>::init() {
  qheader = new QNode<T>;
  qtrailer = new QNode<T>;
  qheader->pred = nullptr, qheader->succ = qtrailer;
  qtrailer->succ = nullptr, qtrailer->pred = qheader;
  /*above below 自然是nullptr，_size已经更新为0*/
}

template <typename T>
T Quadlist<T>::remove(QPtr<T> x) {
  x->succ->pred = x->pred;
  x->pred->succ = x->succ;
  _size--;
  auto res = x->entry;
  delete x;
  return res;
}

template <typename T>
int Quadlist<T>::clear() {
  int res = _size;
  while (_size > 0) remove(qheader->succ);
  return res;
}


}