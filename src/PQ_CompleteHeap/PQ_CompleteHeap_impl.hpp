#pragma once

// #define __PQ__SWAP_METHOD__

#ifdef __PQ__SWAP_METHOD__
#include <utility>
#endif

namespace CYT_DSA {
template <typename T>
rank PQ_CH<T>::percolateUp(T* const A, rank i) {
#ifdef __PQ__SWAP_METHOD__  // 此时是一步一步交换上滤
  while (i > 0) {
    rank p = Parent(i);
    if (A[i] < A[p] || A[p] == A[i]) break;
    std::swap(A[i], A[p]);
    i = p;
  }
#else  // 此时是不交换上滤, 而是一个一个挪过去，最后再赋值，由3k变为k
  const T target_elem = A[i];
  while (i > 0) {
    rank p = Parent(i);
    if (target_elem < A[p] || target_elem == A[p]) break;
    A[i] = A[p];
    i = p;
  }
  A[i] = target_elem;
#endif
  return i;
}

template <typename T>
rank PQ_CH<T>::maxIn3(const T* const elem, const T& target, const rank i,
                      const int n) {
  if (RChildValid(i, n)) {
    const rank greater = Greater(elem, LChild(i), RChild(i));
    return elem[greater] < target ? i : greater;
  } else if (LChildValid(i, n)) {
    return elem[LChild(i)] < target ? i : LChild(i);
  } else {
    return i;
  }
}

template <typename T>
rank PQ_CH<T>::percolateDown(T* const Array, rank i, const rank n) {
  rank j = 0;
#ifdef __PQ__SWAP_METHOD__ /*此时是一路交换下去*/
  while (i != (j = ProperParent(Array, i, n))) {
    std::swap(Array[i], Array[j]);
    i = j;
  }
#else /*此时不交换下去，最后再赋值*/
  const T target_elem = Array[i];
  // 这里容易出错， 不能使用ProperParent了，因为elem[i]不再是应该参与比较的值
  while (i != (j = maxIn3(Array, target_elem, i, n))) {
    Array[i] = Array[j];
    i = j;
  }
  Array[i] = target_elem;
#endif
  return i;
}

template <typename T>
void PQ_CH<T>::heapify(T* const A, const rank n) {
  for (rank i = LastInternal(n); InHeap(i, n); i--) {
    percolateDown(A, i, n);
  }
}

template <typename T>
PQ_CH<T>::PQ_CompleteHeap(T* const A, const rank n) : Vector<T>(A, n) {
  /*首先激活基类构造*/
  heapify(this->elem, this->size());
}

}  // namespace CYT_DSA