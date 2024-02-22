#pragma once

namespace CYT_DSA {
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& src) {
  copy(src.elem, 0, src.__size);
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& src) noexcept {
  elem = src.elem;
  __size = src.__size;
  __capacity = src.__capacity;
  src.elem = nullptr;
}

}  // namespace CYT_DSA