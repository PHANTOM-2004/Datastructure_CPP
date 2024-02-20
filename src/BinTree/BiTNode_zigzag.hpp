#pragma once

namespace CYT_DSA {

template <typename T>
BPtr<T> BiTNode<T>::zag() {
  BPtr<T> rChild = this->right;
  // 父亲接线接过来，如果不是根节点
  if (this->parent != nullptr) {
    if (IsLChild(this))
      this->parent->left = rChild;
    else
      this->parent->right = rChild;
  }
  rChild->parent = this->parent;
  // 更新this的父亲
  this->parent = rChild;

  // 更新右儿子的左儿子
  this->right = rChild->left;
  if (rChild->left != nullptr) rChild->left->parent = this;
  rChild->left = this;
  // 更新this高度
  this->height = std::max(stature(right), stature(left));
  // 更新rChild高度
  rChild->height = std::max(stature(rChild->left), stature(rChild->right));

  // 更新rChild爸爸高度
  for (BPtr<T> x = rChild->parent; x != nullptr; x = x->parent) {
    if (HeightUpdated(x)) {
      break;
    } else {
      x->height = std::max(stature(x->left), stature(x->right)) + 1;
    }
  }
  return rChild;
}

template <typename T>
BPtr<T> BiTNode<T>::zig() {
  BPtr<T> lChild = this->left;
  if (this->parent != nullptr) {
    if (IsLChild(this))
      this->parent->left = lChild;
    else
      this->parent->right = lChild;
  }
  lChild->parent = this->parent;
  this->parent = lChild;

  this->left = lChild->right;
  if (lChild->right != nullptr) lChild->right->parent = this;
  lChild->right = this;

  this->height = 1 + std::max(stature(left), stature(right));
  lChild->height = 1 + std::max(stature(lChild->left), stature(lChild->right));

  for (BPtr<T> x = lChild->parent; x != nullptr; x = x->parent) {
    if (HeightUpdated(x))
      break;
    else
      x->height = std::max(stature(x->left), stature(x->right));
  }
  return lChild;
}

}  // namespace CYT_DSA
