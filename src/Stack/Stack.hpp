#pragma once

#include "Vector/Vector.hpp"

namespace CYT_DSA {

template <typename T>
class Stack : private Vector<T> {
 public:
  using Vector<T>::size;
  using Vector<T>::empty;
  using Vector<T>::traverse;
  void push(const T& e) { Vector<T>::push_back(e); }
  T pop() { return Vector<T>::pop_back(); }
  T& top() const { return Vector<T>::elem[Vector<T>::__size - 1]; }
  // Stack()
};

}  // namespace CYT_DSA