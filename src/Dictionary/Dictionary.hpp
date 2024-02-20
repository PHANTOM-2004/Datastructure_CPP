#pragma once

namespace CYT_DSA {
template <typename K, typename V>
struct  Dictionary {
  virtual int size() const = 0;
  virtual bool put(K, V) = 0;
  virtual V* get(K key) = 0;
  virtual bool remove(K k) = 0;
};

}  // namespace CYT_DSA