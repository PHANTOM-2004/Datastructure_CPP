#pragma once
#include "PQ_CompleteHeap/Heap_build.hpp"

namespace CYT_DSA {
template <typename T> void Vector<T>::unsort(rank low, rank high) {
  T *__elem = elem + low;
  for (rank i = high - low; i > 1; i--) {
    std::swap(__elem[i - 1], __elem[rand() % i]);
  }
}

template <typename T> void Vector<T>::sort(rank low, rank high) {
  constexpr int opt = 5;
  switch (opt) {
  case 0:
    mergeSort(low, high);
    break;
  case 1:
    selectionSort(low, high);
    break;
  case 2:
    insertionSort(low, high);
    break;
  case 3:
    heapSort(low, high);
    break;
  case 4:
    quickSort(low, high);
    break;
  case 5:
    quickSort_I(low, high);
    break;
  default:
    break;
  }
}

template <typename T> void Vector<T>::merge(rank low, rank mid, rank high) {
  T *A = elem + low;
  rank lb = mid - low;
  T *B = new T[lb];
  rank lc = high - mid;
  T *C = elem + mid;
  for (rank i = 0; i < lb; i++)
    B[i] = A[i];

  rank i = 0, j = 0, tot = 0;
  while (i < lb && j < lc) {
    if (B[i] < C[j] || B[i] == C[j]) {
      A[tot++] = B[i++];
    } else {
      A[tot++] = C[j++];
    }
  }
  while (i < lb)
    A[tot++] = B[i++];
  delete[] B;
}

template <typename T> void Vector<T>::mergeSort(rank low, rank high) {
  if (high - low < 2)
    return;
  rank mid = (low + high) / 2;
  mergeSort(low, mid);
  mergeSort(mid, high);
  if (elem[mid - 1] > elem[mid])
    merge(low, mid, high);
}

template <typename T> void Vector<T>::selectionSort(rank low, rank high) {
  rank n = __size, pos = 0;
  while (n > 1) {
    rank pos = max_pos(0, n);
    std::swap(elem[pos], elem[--n]);
  }
}

template <typename T> void Vector<T>::insertionSort(rank low, rank high) {
  rank sorted_tail = 1;
  //[0,sorted_tail)
  rank ins_pos = 0;
  while (sorted_tail < __size) {
    ins_pos = search(elem[sorted_tail], 0, sorted_tail) + 1;
    insert(ins_pos, erase(sorted_tail));
    sorted_tail++;
  }
}

template <typename T> void Vector<T>::heapSort(rank low, rank high) {
  rank n = high - low;
  T *A = elem + low;
  HeapBuild<T>::heapify(A, n);
  while (--n) {
    std::swap(A[0], A[n]);
    HeapBuild<T>::percolateDown(A, 0, n);
  }
}

template <typename T> rank Vector<T>::partition(rank low, rank high) {
  std::swap(elem[low], elem[low + rand() % (high - low)]);
  const auto pivot = elem[low];
  while (low < high) {
    do
      high--;
    while (low < high && pivot <= elem[high]);
    if (low < high)
      elem[low] = elem[high];

    do
      low++;
    while (low < high && elem[low] <= pivot);
    if (low < high)
      elem[high] = elem[low];
  }
  //这里需要认真推敲，为什么return high, 分为两种情况，一种是low == high ,
  //另一种是low == high + 1;
  elem[high] = pivot;
  return high;
}

template <typename T> void Vector<T>::quickSort(rank low, rank high) {
  if (high - low < 2)
    return;
  const rank mid = partition(low, high);
  quickSort(low, mid);
  quickSort(mid + 1, high);
}

template <typename T> void Vector<T>::quickSort_I(rank low, rank high) {
  if (high - low < 2)
    return;
  Vector<rank> callstk;
  auto put = [&callstk](const rank low, const rank high) {
    if (high - low >= 2) {
      callstk.push_back(low);
      callstk.push_back(high);
    }
  };
  auto get = [&callstk](rank &low, rank &high) {
    high = callstk.pop_back();
    low = callstk.pop_back();
  };

  put(low, high);
  while (callstk.size()) {
    get(low, high);
    const rank mid = partition(low, high);
    if (high - mid > mid - low) {
      put(mid + 1, high);
      put(low, mid);
    } else {
      put(low, mid);
      put(mid + 1, high);
    }
  }
}
} // namespace CYT_DSA