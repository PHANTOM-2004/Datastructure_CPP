#pragma once
#include "BinTree/BinTree.hpp"

namespace CYT_DSA {
template <typename T>
class BST : public BinTree<T> {
 public:
  // 基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
  virtual BPtr<T>& search(const T& e);  // 查找
  virtual BPtr<T> insert(const T& e);   // 插入
  virtual bool remove(const T& e);      // 删除
  void stretchByZag(BPtr<T>&);
  void stretchByZig(BPtr<T>&);
  void stretchByZag() { stretchByZag(this->_root); }
  void stretchByZig() { stretchByZig(this->_root); };

 protected:
  mutable BPtr<T> _hot = nullptr;  // “命中”节点的父亲

  // 按照“3 + 4”结构，联接3个节点及四棵子树
  BPtr<T> connect34(BPtr<T>, BPtr<T>, BPtr<T>, BPtr<T>, BPtr<T>, BPtr<T>,
                    BPtr<T>);
  BPtr<T> rotateAt(BPtr<T> x);  // 对x及其父亲、祖父做统一旋转调整
  static BPtr<T> erase(BPtr<T>& hot, BPtr<T>& x);
};

}  // namespace CYT_DSA

#include "BST_impl.hpp"
