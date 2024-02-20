#pragma once

namespace CYT_DSA {

template <typename K, typename V>
bool Hashtable<K, V>::put(K key, V value) {
  int r = probe4Hit(key);
  if (ht[r] != nullptr) return false;  // 已经存在了

  r = probe4Free(key);
  ht[r] = new Entry<K, V>(key, value);
  this->N_size++;

  if (lazyRemoval->test(r) == true) this->lazyRemoval->clear(r);
  if ((N_size + lazyRemoval->truebit()) * 2 > M_capacity) rehash();

  return true;
}
template <typename K, typename V>
bool Hashtable<K, V>::put(Entry<K,V>* origin) {
  const auto key = origin->key;
  const auto value = origin->value;
  int r = probe4Hit(key);
  if (ht[r] != nullptr) return false;  // 已经存在了
  //这是一个新表
  r = probe4Free(key);
  ht[r] = origin;
  this->N_size++;

  //下面两种情况不太可能发生
  //if (lazyRemoval->test(r) == true) this->lazyRemoval->clear(r);
  //if ((N_size + lazyRemoval->truebit()) * 2 > M_capacity) rehash();

  return true;
}

}  // namespace CYT_DSA