#pragma once

namespace CYT_DSA {

template <typename T>
T Vector<T>::erase(const rank r) {
  auto res = elem[r];
  for (int i = r + 1; i < __size; i++) {
    elem[i - 1] = elem[i];
  }
  __size--;
  shrink();
  return res;
}

template <typename T>
int Vector<T>::erase(rank low, rank high) {
  rank old_size = __size;
  while (high < __size) {
    elem[low++] = elem[high++];
  }
  __size--;
  shrink();
  return old_size - __size;
}

template <typename T>
void Vector<T>::insert(const rank r, T const& e) {
  expand();
  for (rank i = __size; i > r; i--) {
    elem[i] = elem[i - 1];
  }
  elem[r] = e;
  __size++;
}

template <typename T>
rank Vector<T>::find(T const& e, rank low, rank high) const {
  while (--high >= low) {
    if (elem[high] == e) return high;
  }
  return npos;
}

template <typename T>
rank Vector<T>::search(T const& e, rank low, rank high) const {
  return binary_search(e, low, high);
}

// 多个元素命中， 返回命中的rank最大者；如果找不到，返回失败的位置 <= e最大值
template <typename T>
rank Vector<T>::binary_search(T const& e, rank low, rank high) const {
  rank mid = 0;
  while (low < high) {
    mid = (low + high) / 2;
    if (e < elem[mid])
      high = mid;
    else
      low = mid + 1;
  }
  return --low;
}

template <typename T>
int Vector<T>::dedupilicate() {
  const rank old_size = __size;
  for (rank i = 1; i < __size;) {
    rank res = find(elem[i], 0, i);
    if (res == npos)
      i++;
    else
      erase(res);
  }

  return old_size - __size;
}

template <typename T>
int Vector<T>::uniquify() {
  const rank old_size = __size;
  rank i = 0, j = 1;
  while (j < __size) {
    if (elem[i] == elem[j])
      j++;
    else
      elem[++i] = elem[j++];
  }
  __size = i;
  shrink();
  return old_size - __size;
}

template <typename T>
rank Vector<T>::max_pos(rank low, rank high) const {
  rank res = low;
  while (low < high) {
    if (!(elem[res] > elem[low])) {
      res = low;
    }
    low++;
  }
  return res;
}
}  // namespace CYT_DSA