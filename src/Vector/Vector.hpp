#pragma once

#include <iostream>

namespace CYT_DSA {
using rank = int;

template <typename T> class Vector {
public:
  static const rank npos = -1;
  /*constructor*/
  explicit Vector() { elem = new T[__capacity]{}; };
  explicit Vector(const T val, const rank c = VECTOR_DEFAULT_CAPACITY,
                  const rank size = 0);
  Vector(const T *A, const rank n);
  Vector(const T *A, const rank __low, const rank __high);
  Vector(const Vector<T> &src);
  Vector(const Vector<T> &src, const rank __low, const rank __high);
  Vector(Vector<T> &&src) noexcept;

  /*deconstructor*/
  ~Vector() { delete[] elem; }

  /*read only*/
  rank size() const { return __size; };
  bool empty() const { return !__size; };
  bool disordered() const;
  rank find(const T &e) const { return find(e, 0, __size); };
  rank find(const T &e, rank __low, rank __high) const;
  rank search(const T &e) const { return search(e, 0, __size); };
  rank search(const T &e, rank __low, rank __high) const;

  /*operator*/
  T &operator[](const rank r) const { return elem[r]; };
  Vector<T> &operator=(const Vector<T> &src);
  Vector<T> &operator=(Vector<T> &&src) noexcept;

  /*do*/
  T erase(const rank r);
  int erase(rank __low, rank __high);
  void insert(const rank r, T const &e);
  void push_back(const T &e) { insert(__size, e); };
  void push_front(const T &e) { insert(0, e); };
  T pop_back() { return erase(__size - 1); };
  T pop_front() { return erase(0); };

  void unsort() { unsort(0, __size); };
  void unsort(rank __low, rank __high);
  void sort() { sort(0, __size); };
  void sort(rank __low, rank __high);

  int uniquify();
  int dedupilicate();
  void clear() {
    __size = 0;
    shrink();
  }
  rank max_pos(rank __low, rank __high) const;
  rank max_pos() const { return max_pos(0, __size); }

  /*traverse*/
  void traverse(void (*p)(T &));
  template <typename func_type> void traverse(const func_type p);

protected:
  static const rank VECTOR_DEFAULT_CAPACITY = 3;
  rank __size = 0;
  rank __capacity = VECTOR_DEFAULT_CAPACITY;
  T *elem = nullptr;
  void copy(const T *__src, const rank __low, const rank __high);
  void expand();
  void shrink();
  void selectionSort(rank low, rank high);
  void insertionSort(rank low, rank high);
  void mergeSort(rank low, rank high);
  void heapSort(rank low, rank high);
  // 约定这里是不重叠区间
  void merge(rank low, rank mid, rank high);

  rank binary_search(const T &elem, rank low, rank high) const;
  // void fibo_search(const T &elem, rank low, rank high) const;
};

} // namespace CYT_DSA

#include "Vector_impl.hpp"