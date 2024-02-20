#pragma once

#include "Bitmap/Bitmap.hpp"
#include "Dictionary/Dictionary.hpp"
#include "Dictionary/Entry.hpp"

namespace CYT_DSA {
using hash_size = unsigned long long;
template <typename K, typename V>
class Hashtable : public Dictionary<K, V> {
 public:
  Hashtable(const int __init = 5);
  ~Hashtable();
  int capacity() const { return M_capacity; };
  int size() const { return N_size; };
  bool put(K, V);
  V* get(K key);
  bool remove(K key);

 protected:
  bool put(Entry<K, V>*);
  int probe4Hit(const K& key);
  int probe4Free(const K& key);
  void rehash();
  constexpr bool laszilyRemoved(const int r) { return lazyRemoval->test(r); }
  constexpr void setAsRemoved(const int r) { lazyRemoval->set(r); }

 private:
  Entry<K, V>** ht;
  int M_capacity;
  int N_size;
  Bitmap* lazyRemoval;
};

}  // namespace CYT_DSA

#include "Hashtable_impl.hpp"