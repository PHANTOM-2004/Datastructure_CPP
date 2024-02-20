#pragma once

namespace CYT_DSA {

template <typename T>
List<T>::~List() {
  clear();
  delete header.ptr;
  delete trailer.ptr;
}

}  // namespace CYT_DSA
