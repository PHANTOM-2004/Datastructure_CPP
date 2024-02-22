#pragma once

namespace CYT_DSA {
template <class T>
bool RBTree<T>::remove(const T& e) {
  auto& x = search(e);
  if (x == nullptr) return false;

  auto r = erase(this->_hot, x);
  this->_size--;
  if (!this->_size) return true;

  //删除了根节点,涂黑
  if (this->_hot == nullptr) {
    this->_root->_color = RBcolor::black;
    this->updateHeight(this->_root);
    return true;
  }
  //黑平衡,其实也就是x为red的情况
  if (BlackHeightUpdated(this->_hot)) return true;
  //不平衡,对应x为black,r为red的情况
  if (IsRed(r)) {
    //染黑并且黑高度++
    r->_color = RBcolor::black;
    r->height++;
    return true;
  }

  //解决BB问题
  solveDoubleBlack(r);
  return true;
}
}  // namespace CYT_DSA