#pragma once

namespace CYT_DSA {

template <typename T>
List_iterator<T> List<T>::operator[](rank r) const {
  List_iterator<T> iter = header;
  while (r--) ++iter;
  return iter;
}

}  // namespace CYT_DSA