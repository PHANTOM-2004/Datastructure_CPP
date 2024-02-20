#pragma once
#include "../PQ_CompleteHeap/PQ_CompleteHeap.hpp"

namespace CYT_DSA {
template <typename T>
void Vector<T>::unsort(rank low, rank high) {
  T* __elem = elem + low;
  for (rank i = high - low; i > 1; i--) {
    std::swap(__elem[i - 1], __elem[rand() % i]);
  }
}

template <typename T>
void Vector<T>::sort(rank low, rank high) {
  constexpr int opt = 3;
  switch (opt) {
    case 0:
      mergeSort(low, high);
      break;
    case 1:
       selectionSort(low, high);
      break;
    case 2:
       insertionSort(low, high);
    case 3:
      heapSort(low, high);
    default:
      break;
  }
}

template <typename T>
void Vector<T>::merge(rank low, rank mid, rank high) {
  T* A = elem + low;
  rank lb = mid - low;
  T* B = new T[lb];
  rank lc = high - mid;
  T* C = elem + mid;
  for (rank i = 0; i < lb; i++) B[i] = A[i];

  rank i = 0, j = 0, tot = 0;
  while (i < lb && j < lc) {
    if (B[i] < C[j] || B[i] == C[j]) {
      A[tot++] = B[i++];
    } else {
      A[tot++] = C[j++];
    }
  }
  while (i < lb) A[tot++] = B[i++];
  delete[] B;
}

template <typename T>
void Vector<T>::mergeSort(rank low, rank high) {
  if (high - low < 2) return;
  rank mid = (low + high) / 2;
  mergeSort(low, mid);
  mergeSort(mid, high);
  if (elem[mid - 1] > elem[mid]) merge(low, mid, high);
}

template <typename T>
void Vector<T>::selectionSort(rank low, rank high) {
  rank n = __size, pos = 0;
  while (n > 1) {
    rank pos = max_pos(0, n);
    std::swap(elem[pos], elem[--n]);
  }
}

template<typename T>
void Vector<T>::insertionSort(rank low, rank high) {
  rank sorted_tail = 1;
  //[0,sorted_tail)
  rank ins_pos = 0;
  while (sorted_tail < __size) {
    ins_pos = search(elem[sorted_tail], 0, sorted_tail) + 1;
    insert(ins_pos, erase(sorted_tail));
    sorted_tail++;
  }
}

template <typename T>
void Vector<T>::heapSort(rank low, rank high) {
  rank n = high - low;
  T* A = elem + low;
  PQ_CH<T>::heapify(A, n);
  while (--n) {
    std::swap(A[0], A[n]);
    PQ_CH<T>::percolateDown(A, 0, n);
  }
}

}  // namespace CYT_DSA