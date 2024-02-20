#pragma once

namespace CYT_DSA {

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsPred(const T& e) {
  auto newnode = new ListNode(e, pred, this);
  this->pred->succ = newnode;
  this->pred = newnode;
  return newnode;
}

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsSucc(const T& e) {
  auto newnode = new ListNode(e, this, succ);
  this->succ->pred = newnode;
  this->succ = newnode;
  return newnode;
}

}  // namespace CYT_DSA