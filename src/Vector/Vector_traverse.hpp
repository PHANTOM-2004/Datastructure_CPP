#pragma

namespace CYT_DSA {
template <typename T>
template <typename func_type>
void Vector<T>::traverse(func_type func) {
  for (int i = 0; i < __size; i++) {
    func(elem[i]);
  }
  std::cout << std::endl;
}

template <typename T>
void Vector<T>::traverse(void (*func)(T &)) {
  for (int i = 0; i < __size; i++) {
    func(elem[i]);
  }
  std::cout << std::endl;
}

}