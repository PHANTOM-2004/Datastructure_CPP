#pragma once

namespace CYT_DSA {
template <typename K, typename V>
V* Hashtable<K, V>::get(K key) {
  const int r = probe4Hit(key);
  return ht[r] != nullptr ? &ht[r]->value : nullptr;
}
}  // namespace CYT_DSA