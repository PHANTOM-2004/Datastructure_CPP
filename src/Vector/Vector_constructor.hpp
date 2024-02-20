#pragma once

namespace CYT_DSA {
template <typename T>
Vector<T>::Vector(const T val, const rank c, const rank size)
    : __capacity(c), __size(size) {
  if (__capacity < VECTOR_DEFAULT_CAPACITY)
    __capacity = VECTOR_DEFAULT_CAPACITY;
  if (__size < 0) {
    __size = 0;
    return;
  }

  elem = new T[__capacity];
  for (rank i = 0; i < __size; i++) elem[i] = val;
}

template <typename T>
Vector<T>::Vector(const T* A, const rank n) {
  copy(A, 0, n);
}

template <typename T>
Vector<T>::Vector(const T* A, const rank low, const rank high) {
  copy(A, low, high);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& src) {
  copy(src.elem, 0, src.__size);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& src, const rank low, const rank high) {
  copy(src.elem, low, high);
}

template <typename T>
Vector<T>::Vector(Vector<T>&& src) noexcept {
  elem = src.elem;
  __capacity = src.__capacity;
  __size = src.__size;
  src.elem = nullptr;
}

}  // namespace CYT_DSA