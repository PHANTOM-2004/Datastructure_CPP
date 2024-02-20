#pragma once
#include "../BST/BST.hpp"

namespace CYT_DSA {
template <typename T>
class Splay : public BST<T> {
 public:
  virtual BPtr<T>& search(const T& e);
  virtual BPtr<T> insert(const T& e);
  virtual bool remove(const T& e);
 protected:
  BPtr<T> splay(BPtr<T> v);
};
}  // namespace CYT_DSA

#include "Splay_impl.hpp"