#pragma once

namespace CYT_DSA {

template <typename T>
void List<T>::traverse(void (*func)(T&)) {
  for (auto ptr = first(); ptr != trailer; ptr++) {
    func(*ptr);
  }
}

template <typename T>
template <typename func_type>
void List<T>::traverse(func_type& func) {
  for (auto ptr = first(); ptr != trailer; ptr++) {
    func(*ptr);
  }
}

}  // namespace CYT_DSA