#pragma once

namespace CYT_DSA {
template <typename T>
struct QNode;

template <typename T>
using QPtr = QNode<T>*;  // 节点位置

template <typename T>
using QNodePosi = QNode<T>*;  // 节点位置

template <typename T>
struct QNode {  // 四联节点T entry; //所存词条
  T entry;
  QPtr<T> pred, succ, above, below;  // 前驱、后继、上邻、下邻
  QNode(T e = T(), QPtr<T> p = nullptr, QPtr<T> s = nullptr,
        QPtr<T> a = nullptr, QPtr<T> b = nullptr)  // 构造器
      : entry(e), pred(p), succ(s), above(a), below(b) {}
  QPtr<T> insert(T const& e, QPtr<T> b = nullptr);
  // 将e作为当前节点的后继、b的上邻插入
};
}  // namespace CYT_DSA



namespace CYT_DSA {
template <typename T>
QPtr<T> QNode<T>::insert(const T& e, QPtr<T> b) {
  // 为什么这里直接让above是nullptr，不考虑above的问题？
  QPtr<T> new_node = new QNode<T>(e, this, this->succ, nullptr, b);
  this->succ->pred = new_node;  // 由于水平头尾结点的存在因此不用担心nullptr
  this->succ = new_node;
  if (b != nullptr) b->above = new_node;
  return new_node;
}

}  // namespace CYT_DSA