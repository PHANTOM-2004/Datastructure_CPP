#pragma once

namespace CYT_DSA {
template <typename T>
BPtr<T> BST<T>::connect34(BPtr<T> a, BPtr<T> b, BPtr<T> c, BPtr<T> T0,
                          BPtr<T> T1, BPtr<T> T2, BPtr<T> T3) {
  a->left = T0;
  if (T0 != nullptr) T0->parent = a;
  a->right = T1;
  if (T1 != nullptr) T1->parent = a;
  this->updateHeight(a);

  c->left = T2;
  if (T2 != nullptr) T2->parent = c;
  c->right = T3;
  if (T3 != nullptr) T3->parent = c;
  this->updateHeight(c);

  b->left = a;
  a->parent = b;
  b->right = c;
  c->parent = b;
  this->updateHeight(b);
  return b;
}

}  // namespace CYT_DSA