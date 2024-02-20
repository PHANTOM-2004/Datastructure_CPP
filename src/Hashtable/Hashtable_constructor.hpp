#pragma once

#include "Prime/primeNLT.hpp"

namespace CYT_DSA {

template <typename K, typename V>
Hashtable<K, V>::Hashtable(const int __init) {
  this->M_capacity = Prime::primeNLT(__init);
  this->N_size = 0;
  this->ht = new Entry<K, V>* [M_capacity] { nullptr };
  this->lazyRemoval = new Bitmap(M_capacity);
}

template <typename K, typename V>
Hashtable<K, V>::~Hashtable() {
  for (int i = 0; i < M_capacity; i++)
    if (ht[i] != nullptr) delete ht[i];
  delete[] ht;
  delete lazyRemoval;
}

}  // namespace CYT_DSA