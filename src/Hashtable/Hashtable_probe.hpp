#pragma once

namespace CYT_DSA {

static hash_size HashCode(const char c) { return c; }
static hash_size HashCode(const int c) { return c; }
static hash_size HashCode(const long long c) { return (c >> 32) + (hash_size)c; }

static hash_size HashCode(const char* p) {
  constexpr hash_size BASE = 33;
  hash_size hash = 0;
  for (const char* c = p; *c; c++) {
    hash = hash * BASE + *c;
  }
  return hash;
}


template <typename K, typename V>
int Hashtable<K, V>::probe4Hit(const K& key) {
  int r = HashCode(key) % M_capacity;
  while ((ht[r] != nullptr && ht[r]->key != key) ||
         (ht[r] == nullptr && laszilyRemoved(r))) {
    r = (r + 1) % M_capacity;
  }
  return r;
}

template <typename K, typename V>
int Hashtable<K, V>::probe4Free(const K& key) {
  int r = HashCode(key) % M_capacity;
  while (ht[r] != nullptr )
    r = (r + 1) % M_capacity;
  return r;
}

}  // namespace CYT_DSA