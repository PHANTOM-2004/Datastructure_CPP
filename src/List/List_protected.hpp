#pragma once

namespace CYT_DSA {
template <typename T>
void List<T>::init() {
  header = List_iterator<T>(new ListNode<T>);
  trailer = List_iterator<T>(new ListNode<T>);
  header->succ = trailer.ptr;
  trailer->pred = header.ptr;
  _size = 0;
}

template<typename T>
rank List<T>::clear() {
  auto res = _size;
  List_iterator<T> iter = first();
  while (iter != trailer) {
    delete (iter++).ptr;
  }
  return res;
}

template<typename T>
void List<T>::copy(List_iterator<T> iter, rank r){
  while (r--) {
    push_back(*(iter++));//trailer 前面
  }
}




}  // namespace CYT_DSA