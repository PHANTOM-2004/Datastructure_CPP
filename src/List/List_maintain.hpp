#pragma once

namespace CYT_DSA {

template <typename T>
T List<T>::erase(List_iterator<T> ptr) {
  auto res = ptr->data;
  ptr->pred->succ = ptr->succ;
  ptr->succ->pred = ptr->pred;
  delete ptr.ptr;
  _size--;
  return res;
}

template <typename T>
List_iterator<T> List<T>::find(const T& e, rank n, List_iterator<T> ptr) const {
  while (n--) {
    if (*--ptr == e) return ptr;
  }
  return List_iterator<T>();
}

template <typename T>
rank List<T>::dedup() {
  if (_size < 2) return 0;

  rank old_size = _size;
  rank r = 0;
  for (auto ptr = first(); ptr != trailer; ptr++) {
    auto target = find(*ptr, r, ptr);
    if (valid(target))
      erase(target);
    else
      r++;
  }
  return old_size - _size;
}

template <typename T>
rank List<T>::uniquify() {
  if (_size < 2) return 0;

  rank old_size = _size;
  auto low = first();
  auto fast = List_iterator<T>(low->succ);

  while (fast != trailer) {
    if (*fast == *low) {
      erase(low);
      low = fast++;
    } else
      low = fast++;
  }

  return old_size - _size;
}

template <typename T>
List_iterator<T> List<T>::search(T const& e, rank n, List_iterator<T> p) const {
  while (n-- >= 0) {
    if (*--p <= e) break;
  }
  return p;
}

template <typename T>
List_iterator<T> List<T>::selectMax(List_iterator<T> p, rank n) const {
  auto iter_max = p;
  while (n--) {
    if (!(*p < *iter_max)) iter_max = p;
    ++p;
  }
  return iter_max;
}

template <typename T>
void List<T>::reverse() {
  if (_size < 2) return;

#define __list_reverse_opt  3
// 共有四种方法，我写的是最蠢的一种
#if __list_reverse_opt == 1
  auto first_node = last().ptr;
  auto last_node = first().ptr;

  auto p = header.ptr;
  auto q = p->succ;
  auto next = q->succ;

  while (next != trailer.ptr) {
    next = q->succ;
    q->succ = p;
    p = q;
    q = next;
  }

  p = trailer.ptr;
  q = trailer->pred;
  next = q->pred;
  while (next != header.ptr) {
    next = q->pred;
    q->pred = p;
    p = q;
    q = next;
  }

  header->succ = first_node;
  first_node->pred = header.ptr;

  trailer->pred = last_node;
  last_node->succ = trailer.ptr;
#elif __list_reverse_opt == 2
  // 两次遍历，这里实际没有必要使用三个指针
  for (auto p = header.ptr, q = header->succ; p != trailer.ptr;
       p = q, q = q->succ) {
    p->pred = q;
  }

  trailer->pred = nullptr;

  for (auto p = header.ptr, q = header->succ; p != trailer.ptr;
       p = q, q = q->pred) {
    q->succ = p;
  }

  header->succ = nullptr;
  std::swap(header, trailer);

#elif __list_reverse_opt == 3
  // 一次遍历，交换指针
  int i = 0;
  for (auto p = header.ptr; p != nullptr; p = p->pred) {
    i++;
    std::swap(p->pred, p->succ);
  }
  std::swap(header, trailer);
#else
  // 交换值的方法，不推荐，个人觉得，交换可以并不是O(1)的
  int cnt = _size / 2;
  for (auto p = first(), q = last(); cnt > 0; ++p, --q) {
    std::swap(*p, *q);
    cnt--;
  }
#endif
}

}  // namespace CYT_DSA