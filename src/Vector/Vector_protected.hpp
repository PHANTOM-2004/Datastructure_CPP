#pragma once

namespace CYT_DSA {

template <typename T>
void Vector<T>::copy(const T* src, const rank low, const rank high) {
  delete[] elem;
  __size = high - low;
  __capacity = 2 * __size;
  if (__capacity < VECTOR_DEFAULT_CAPACITY)
    __capacity = VECTOR_DEFAULT_CAPACITY;

  elem = new T[__capacity];
  for (rank i = low, j = 0; i < high; i++, j++) {
    elem[j] = src[i];
  }
}

template <typename T>
void Vector<T>::expand() {
  if (__size < __capacity) {
    return;
  }
  __capacity = __capacity * 2;
  if (__capacity < VECTOR_DEFAULT_CAPACITY) {
    __capacity = VECTOR_DEFAULT_CAPACITY;
  }

  T* new_elem = new T[__capacity];
  for (rank i = 0; i < __size; i++) {
    new_elem[i] = elem[i];
  }
  delete[] elem;
  elem = new_elem;
}

template <typename T>
void Vector<T>::shrink() {
  if (4 * __size > __capacity) {
    return;  //__size/__capacity > 1/4, 不必扩容
  }
  __capacity = __capacity / 2;
  if (__capacity < VECTOR_DEFAULT_CAPACITY) {
    __capacity = VECTOR_DEFAULT_CAPACITY;
  }

  T* new_elem = new T[__capacity];
  for (rank i = 0; i < __size; i++) {
    new_elem[i] = elem[i];
  }
  delete[] elem;
  elem = new_elem;
}

}  // namespace CYT_DSA