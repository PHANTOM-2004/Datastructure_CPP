#pragma once

#include "PriorityQueue/PQ.hpp"
#include "Vector/Vector.hpp"
#include "Heap_build.hpp"

namespace CYT_DSA {

template <typename T>
class PQ_CompleteHeap;

template <typename T>
using PQ_CH = PQ_CompleteHeap<T>;


template <typename T>
class PQ_CompleteHeap : public PQ<T>, private Vector<T> {
 public:
  friend Vector<T>;
  PQ_CompleteHeap(T* const A, const rank n);
  PQ_CompleteHeap() = default;
  using Vector<T>::size;
  virtual void push(const T& e) {
    this->push_back(e);
    HeapBuild<T>::percolateUp(this->elem, size() - 1);
  };
  virtual const T& top() const { return this->elem[0]; };
  virtual void pop() {
    this->elem[0] = this->elem[--this->__size];
    HeapBuild<T>::percolateDown(this->elem, 0, size());
  }
};


template <typename T>
PQ_CompleteHeap<T>::PQ_CompleteHeap(T* const A, const rank n) : Vector<T>(A, n) {
  /*首先激活基类构造*/
  //  PQ_CH<T> * ptr = nullptr;
  HeapBuild<T>::heapify(this->elem, this->size());
}

}  // namespace CYT_DSA
