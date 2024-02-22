#pragma once
#include "List/List.hpp"

namespace CYT_DSA {
template <typename T>
class Queap;

template <typename T>
class Queue : private List<T> {
  friend class Queap<T>;

 public:
  using List<T>::size;
  using List<T>::empty;
  using List<T>::push_back;
  using List<T>::push_front;
  using List<T>::pop_back;
  using List<T>::pop_front;
  using List<T>::traverse;
  const T& front() const { return *List<T>::first(); }
  const T& back() const { return *List<T>::last(); }

 protected:
  using List<T>::first;
  using List<T>::last;
};

}  // namespace CYT_DSA