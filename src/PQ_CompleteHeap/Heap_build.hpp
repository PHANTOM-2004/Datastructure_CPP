#pragma once

namespace CYT_DSA {
template <typename T> class HeapBuild {
public:
  using rank = int;
  /*@brief 下滤，这里给出了通用的方法，因此多了一些接口*/
  static rank percolateDown(T *const Array, rank i, const rank n);
  /*@brief 上滤, 这里给出了通用的方法，因此多了一些接口*/
  static rank percolateUp(T *const Array, rank i);
  /*@brief Floyd建堆法*/
  static void heapify(T *const A, const rank n);

protected:
  static rank maxIn3(const T *const elem, const T &target, const rank i,
                     const int n);
  // 以下是static函数方法
  static constexpr rank Parent(const rank i) { return (i - 1) / 2; }
  static constexpr rank LChild(const rank i) { return (i + 1) * 2 - 1; }
  static constexpr rank RChild(const rank i) { return (i + 1) * 2; }
  static constexpr bool InHeap(const rank i, const rank n) {
    return i >= 0 && i < n;
  }
  /*@brief 是否有左孩子*/
  static constexpr bool LChildValid(const rank i, const rank n) {
    return InHeap(LChild(i), n);
  }
  /*@brief 是否有左右孩子*/
  static constexpr bool RChildValid(const rank i, const rank n) {
    return InHeap(RChild(i), n);
  }
  /*@brief 父子至多三人的最大者*/
  static constexpr rank ProperParent(const T *__elem, const rank i,
                                     const rank n) {
    return RChildValid(i, n)
               ? Greater(__elem, i, Greater(__elem, LChild(i), RChild(i)))
           : LChildValid(i, n) ? Greater(__elem, i, LChild(i))
                               : i;
  }
  static constexpr rank Greater(const T *__elem, const rank i, const rank j) {
    return __elem[i] < __elem[j] ? j : i;
  }
  /*最后一个内部节点*/
  static constexpr rank LastInternal(const rank n) { return Parent(n - 1); }
};

} // namespace CYT_DSA

// #define __PQ__SWAP_METHOD__

#ifdef __PQ__SWAP_METHOD__
#include <utility>
#endif

namespace CYT_DSA {
template <typename T> rank HeapBuild<T>::percolateUp(T *const A, rank i) {
#ifdef __PQ__SWAP_METHOD__ // 此时是一步一步交换上滤
  while (i > 0) {
    rank p = Parent(i);
    if (A[i] < A[p] || A[p] == A[i])
      break;
    std::swap(A[i], A[p]);
    i = p;
  }
#else // 此时是不交换上滤, 而是一个一个挪过去，最后再赋值，由3k变为k
  const T target_elem = A[i];
  while (i > 0) {
    rank p = Parent(i);
    if (target_elem < A[p] || target_elem == A[p])
      break;
    A[i] = A[p];
    i = p;
  }
  A[i] = target_elem;
#endif
  return i;
}

template <typename T>
rank HeapBuild<T>::maxIn3(const T *const elem, const T &target, const rank i,
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
rank HeapBuild<T>::percolateDown(T *const Array, rank i, const rank n) {
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

template <typename T> void HeapBuild<T>::heapify(T *const A, const rank n) {
  for (rank i = LastInternal(n); InHeap(i, n); i--) {
    percolateDown(A, i, n);
  }
}

} // namespace CYT_DSA
