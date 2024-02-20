#pragma once

namespace CYT_DSA {
template <typename T>
inline static void attachAsLChild(BPtr<T> p, BPtr<T> left) {
  p->left = left;
  if (left != nullptr) left->parent = p;
}

template <typename T>
inline static void attachAsRChild(BPtr<T> p, BPtr<T> right) {
  p->right = right;
  if (right != nullptr) right->parent = p;
}

template <typename T>
BPtr<T> Splay<T>::splay(BPtr<T> v) {
  if (v == nullptr) return nullptr;
  BPtr<T> g{nullptr}, p{nullptr};

  while ((p = v->parent) && (g = p->parent)) {
    BPtr<T> gg = g->parent;
    /*zig&zag*/
    if (IsLChild(v)) {
      if (IsLChild(p)) {
        attachAsLChild(g, p->right);
        attachAsLChild(p, v->right);
        attachAsRChild(p, g);
        attachAsRChild(v, p);
      } else {
        attachAsRChild(g, v->left);
        attachAsLChild(p, v->right);
        attachAsLChild(v, g);
        attachAsRChild(v, p);
      }
    } else {
      if (IsLChild(p)) {
        attachAsRChild(p, v->left);
        attachAsLChild(g, v->right);
        attachAsLChild(v, p);
        attachAsRChild(v, g);
      } else {
        attachAsRChild(g, p->left);
        attachAsRChild(p, v->left);
        attachAsLChild(p, g);
        attachAsLChild(v, p);
      }
    }
    if (gg == nullptr) {  // 说明v是根节点
      v->parent = nullptr;
    } else {
      if (gg->left == g)
        attachAsLChild(gg, v);
      else
        attachAsRChild(gg, v);
      this->updateHeight(g);
      this->updateHeight(p);
      this->updateHeight(v);
    }
  }
  /*结束之后g必然空，但是p不一定*/
  if (p != nullptr) {  // 还要再转一次,
                        // 这里似乎没有必要赋值，因为在while循环里面已经进行过了
    if (IsLChild(v)) {
      attachAsLChild(p, v->right);
      attachAsRChild(v, p);
    } else {
      attachAsRChild(p, v->left);
      attachAsLChild(v, p);
    }
    this->updateHeight(p);
    this->updateHeight(v);
  }
  /*根节点父亲*/
  v->parent = nullptr;
  return v;
}

}  // namespace CYT_DSA