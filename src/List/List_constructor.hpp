#pragma once

namespace CYT_DSA {
template <typename T>
List<T>::List(List<T> const& L) {
  init();
  copy(L.first(), L._size);
}


template <typename T>
List<T>::List(List<T> const& L, rank r, rank n) {
  init();
  copy(L[r], n);
}

template <typename T>
List<T>::List(List_iterator<T> p, rank n) {
  init();
  copy(p, n);
}

}  // namespace CYT_DSA