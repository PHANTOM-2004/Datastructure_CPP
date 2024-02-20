#pragma once

namespace CYT_DSA {
template <typename T>
BPtr<T> BST<T>::rotateAt(BPtr<T> v) {
  BPtr<T> p = v->parent;
  BPtr<T> g = p->parent;
  if (IsLChild(p)) {
    if (IsLChild(v)) {
      p->parent = g->parent;
      return connect34(v, p, g, v->left, v->right, p->right, g->right);
    } else {
      v->parent = g->parent;
      return connect34(p, v, g, p->left, v->left, v->right, g->right);
    }
  } else {
    if (IsRChild(v)) {
      p->parent = g->parent;
      return connect34(g, p, v, g->left, p->left, v->left, v->right);
    } else {
      v->parent = g->parent;
      return connect34(g, v, p, g->left, v->left, v->right, p->right);
    }
  }
}
}  // namespace CYT_DSA