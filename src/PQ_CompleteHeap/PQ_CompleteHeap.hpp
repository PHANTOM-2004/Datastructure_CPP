#pragma once

#include "PriorityQueue/PQ.hpp"
#include "Vector/Vector.hpp"

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
    percolateUp(this->elem, size() - 1);
  };
  virtual const T& top() const { return this->elem[0]; };
  virtual void pop() {
    this->elem[0] = this->elem[--this->__size];
    percolateDown(this->elem, 0, size());
  }

 protected:
  /*@brief 下滤，这里给出了通用的方法，因此多了一些接口*/
  static rank percolateDown(T* const Array, rank i, const rank n);
  /*@brief 上滤, 这里给出了通用的方法，因此多了一些接口*/
  static rank percolateUp(T* const Array, rank i);
  /*@brief Floyd建堆法*/
  static void heapify(T* const A, const rank n);

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
  static constexpr rank ProperParent(const T* __elem, const rank i,
                                     const rank n) {
    return RChildValid(i, n)
               ? Greater(__elem, i, Greater(__elem, LChild(i), RChild(i)))
           : LChildValid(i, n) ? Greater(__elem, i, LChild(i))
                               : i;
  }
  static constexpr rank Greater(const T* __elem, const rank i, const rank j) {
    return __elem[i] < __elem[j] ? j : i;
  }
  /*最后一个内部节点*/
  static constexpr rank LastInternal(const rank n) { return Parent(n - 1); }
  // 以下是成员函数方法
  constexpr rank Greater(const rank i, const rank j) const {
    return this->elem[i] < this->elem[j] ? j : i;
  }
  constexpr bool InHeap(const rank i) const { return i >= 0 && i < size(); }
  /*@brief 是否有左孩子*/
  constexpr bool LChildValid(const rank i) const { return InHeap(LChild(i)); }
  /*@brief 是否有左右孩子*/
  constexpr bool RChildValid(const rank i) const { return InHeap(RChild(i)); }
  /*@brief 父子至多三人的最大者*/
  constexpr rank ProperParent(const rank i) const {
    return RChildValid(i)   ? Greater(i, Greater(LChild(i), RChild(i)))
           : LChildValid(i) ? Greater(i, LChild(i))
                            : i;
  }
  static rank maxIn3(const T* const elem, const T& target, const rank i,
                     const int n);
};

}  // namespace CYT_DSA

#include "PQ_CompleteHeap_impl.hpp"