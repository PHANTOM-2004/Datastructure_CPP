#pragma once

namespace CYT_DSA {

template<typename T>
//@param hot 也就是_hot，deleted结点的father
BPtr<T> BST<T>::erase(BPtr<T>&hot , BPtr<T>& x) {
  BPtr<T> w = x;//@param w 存储着将要删除的结点
  BPtr<T> succ = nullptr;//@param succ 存储着将要接替的结点
  if (HasLChild(x) == false) {
    succ = x->right;
    x = x->right;
  } else if (HasRChild(x) == false) {
    succ = x->left;
    x = x->left;
  } else {//两个结点都有孩子
    w = w->succ();
    std::swap(x->data, w->data);
    succ = w->right;
    auto u = w->parent;
    //正常来说w必然是左孩子，但是当u就是x的时候，w是右孩子
    if (u == x) {//
      u->right = succ;
    }
    else {
      u->left = succ;
    }
  }

  hot = w->parent;
  if (succ != nullptr) succ->parent = hot;
  delete w;
  return succ;
}



template <typename T>
bool BST<T>::remove(const T& e) {
  auto& x = search(e);//x
  if (x == nullptr) return false;
  erase(_hot, x);
  this->_size--;
  this->updateHeightAbove(_hot);
  return true;
}


}  // namespace CYT_DSA