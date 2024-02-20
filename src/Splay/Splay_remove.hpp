#pragma once

namespace CYT_DSA {
template<typename T>
bool Splay<T>::remove(const T& e) {
  //排除找不到的情况
  if (this->_root == nullptr || search(e) == nullptr) return false;
  //否则已经进行了一次查找，找得到的e已经到达了中间，首先记录左右孩子
  BPtr<T> RT = this->_root->right, LT = this->_root->left;
  delete this->_root;
  if (RT == nullptr) {
    this->_root = LT;
    if (LT != nullptr) LT->parent = this->_root;
  } else {
    this->_root = RT;
    this->_root->parent = nullptr;
     //在右子树中进行一次搜索
    search(e);//最小点m就会到达根部
    this->_root->left = LT;
    if (LT != nullptr) LT->parent = this->_root;
  }
  this->_size--;
  if (this->_root != nullptr) this->updateHeight(this->_root);
  return true;
}

}