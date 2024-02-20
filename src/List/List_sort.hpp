#pragma once
#include <utility>

namespace CYT_DSA {

template <typename T>
void List<T>::sort(List_iterator<T> ptr, rank n) {
  constexpr int opt = 1;
  switch (opt) {
    case 0:
      insertionSort(ptr, n);
      break;
    case 1:
      selectionSort(ptr, n);
      break;
    case 2:
      mergeSort(ptr, n);
      break;
    case 3:
      radixSort(ptr, n);
      break;
  }
}

template <typename T>
void List<T>::insertionSort(List_iterator<T> ptr, rank n) {
  if (n < 2) return;
  for (int i = 0; i < n; i++) {
    auto target = search(*ptr, i, ptr);
    insert(target, *ptr);
    erase(ptr++);
  }
}

template <typename T>
void List<T>::selectionSort(List_iterator<T> ptr, rank n) {
    //这个是稳定版本， 因为没有swap
  if (n < 2) return;
  auto tail = ptr;
  auto head = --ptr;
  for (int i = 0; i < n; i++) ++tail;

  while (n > 1) {
    auto cur_max = selectMax(List_iterator<T>(head.ptr->succ), n--);
    insert(erase(cur_max) ,tail--);
  }
}

template <typename T>
List_iterator<T> List<T>::merge(List_iterator<T> iter_a, rank a, List<T>& Lb,
                                List_iterator<T> iter_b, rank b) {
  auto res = iter_a->pred;
  while (b > 0 && iter_a != iter_b) {  // 防止同一个链表的情况
    if (a > 0 && *iter_a <= *iter_b) {
      ++iter_a;
      a--;
    } else {
      insert(*iter_b, iter_a);
      Lb.erase(iter_b++);
      b--;
    }
  }
  return List_iterator<T>(res->succ);
}

template <typename T>
void List<T>::mergeSort(List_iterator<T>& begin, rank n) {
  if (n < 2) return;
  auto mid = n / 2;
  auto begin_last = begin;
  for (int i = 0; i < mid; i++) ++begin_last;

  mergeSort(begin, mid);
  mergeSort(begin_last, n - mid);
  begin = merge(begin, mid, *this, begin_last, n - mid);
}

template <typename T>
void List<T>::radixSort(List_iterator<T> begin, rank n) {
  if (n < 2) return;
  List_iterator<T> tail = begin;
  List_iterator<T> head = --begin;
  for (int i = 0; i < n; i++) ++tail;

  for (unsigned radix = 0x1; radix != 0; radix <<= 1) {
    auto p = head;
    for (int i = 0; i < n; i++)
      if (radix & p->succ->data)
        insert(erase(List_iterator<T>(p.ptr->succ)), tail);
      else
        ++p;
  }
}

}  // namespace CYT_DSA
