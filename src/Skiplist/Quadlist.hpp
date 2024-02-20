#pragma once
#include "QNode.hpp"


namespace CYT_DSA {
template <typename T>
class Quadlist {  // 四联表

 public:
  Quadlist() { init(); }  // 构造
  ~Quadlist() {
    clear();
    delete qheader;
    delete qtrailer;
  }  // 析构
  QNodePosi<T> insert(T const& e, QNodePosi<T> p, QNodePosi<T> b = nullptr) {
    _size++;
    return p->insert(e, b);  // 返回新节点位置（below = NULL）
  }
  // 将e作为p的后继、b的上邻插入};
  int size() const { return _size; }
  // bool empty() const { return _size <= 0; }

  int _size = 0;                   // 节点总数
  QNodePosi<T> qheader, qtrailer;  // 头、尾哨兵
  T remove(QPtr<T>);
 protected:
  void init();
  int clear();  // 初始化、清除
};
}  // namespace CYT_DSA

#include "Quadlist_impl.hpp"