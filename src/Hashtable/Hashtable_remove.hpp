#pragma once

namespace CYT_DSA {

template <typename K, typename V>
bool Hashtable<K, V>::remove(K key) {
  const int r = probe4Hit(key);
  if (ht[r] == nullptr) return false;

  delete ht[r];
  ht[r] = nullptr;
  setAsRemoved(r);
  N_size--;
  //如果怠惰删除多，同样rehash
  if (3 * N_size < lazyRemoval->truebit()) rehash();
  return true;
}

}  // namespace CYT_DSA