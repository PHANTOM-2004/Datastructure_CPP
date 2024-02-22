#pragma once
#include "../BST/BST.hpp"

namespace CYT_DSA {
template <typename T>
class Splay : public BST<T> {
 public:
  BPtr<T>& search(const T& e) override;
  BPtr<T> insert(const T& e) override;
  bool remove(const T& e) override;

 protected:
  BPtr<T> splay(BPtr<T> v);
};
}  // namespace CYT_DSA

#include "Splay_impl.hpp"