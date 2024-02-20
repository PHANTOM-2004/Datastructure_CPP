#pragma once

#include "ListNode.hpp"

namespace CYT_DSA {

template <typename T>
class List;

template <typename T>
struct List_iterator {
  friend class List<T>;

  using ptr_type = ListNodePosi<T>;
  using node_type = ListNodePosi<T>;

  explicit List_iterator(ptr_type p = nullptr) : ptr(p) {}

  List_iterator operator++(int) {
    auto res = *this;
    ++*this;
    return res;
  }
  List_iterator& operator++() {
    ptr = ptr->succ;
    return *this;
  }
  List_iterator operator--(int) {
    auto res = *this;
    --*this;
    return res;
  }
  List_iterator& operator--() {
    ptr = ptr->pred;
    return *this;
  }

  operator bool() const { return ptr; }

  bool operator==(const List_iterator& other) const { return ptr == other.ptr; }
  bool operator!=(const List_iterator& other) const { return ptr != other.ptr; }
  T& operator*() const { return ptr->data; };
  ptr_type operator->() const { return ptr; }

 private:
  ptr_type ptr;
};

}  // namespace CYT_DSA