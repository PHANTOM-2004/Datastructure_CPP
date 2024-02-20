#pragma once
#include "../Prime/primeNLT.hpp"

namespace CYT_DSA {

template <typename K, typename V>
void Hashtable<K, V>::rehash() {
  int old_m = M_capacity;
  auto old_ht = this->ht;
  delete lazyRemoval;
  M_capacity = Prime::primeNLT(N_size * 4);
  lazyRemoval = new Bitmap(M_capacity);
  ht = new Entry<K, V>* [M_capacity] { nullptr };

  for (int i = 0; i < old_m; i++)
    if (old_ht[i] != nullptr) {
      put(old_ht[i]);
    }

  delete old_ht;
}

}