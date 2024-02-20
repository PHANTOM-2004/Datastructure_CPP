#pragma once

#include "ListNode.hpp"  //引入列表节点类
#include "List_iterator.hpp"

namespace CYT_DSA {

template <typename T>
class List {  // 列表模板类

  friend struct List_iterator<T>;

 public:
  // 构造函数
  List() { init(); }                       // 默认
  List(List<T> const& L);                  // 整体复制列表L
  List(List<T> const& L, rank r, rank n);  // 复制列表L中自第r项起的n项
  List(List_iterator<T> p, rank n);  // 复制列表中自位置p起的n项
  // 析构函数
  ~List();  // 释放（包含头、尾哨兵在内的）所有节点

  // 只读访问接口
  rank size() const { return _size; }        // 规模
  bool empty() const { return _size <= 0; }  // 判空
  List_iterator<T> operator[](rank r) const;  // 重载，支持循秩访问（效率低）
  List_iterator<T> first() const { return List_iterator<T>(header->succ); }
  List_iterator<T> last() const { return List_iterator<T>(trailer->pred); }
  // 判断位置p是否对外合法
  bool valid(List_iterator<T> p) const {
    return p.ptr && (trailer != p) && (header != p);
  }  // 将头、尾节点等同于NULL
  // 从p开始向前找n个,ptr的n个真前驱// 无序区间查找
  List_iterator<T> find(T const& e, rank n, List_iterator<T> p) const;
  List_iterator<T> find(T const& e) const { return find(e, _size, trailer); }
  // 有序列表查找, n个真前驱，服务于插入排序，向前找到<=e 最大值
  List_iterator<T> search(T const& e, rank n, List_iterator<T> p) const;
  List_iterator<T> search(T const& e) const {
    return search(e, _size, trailer);
  }
  // 在p及其n-1个后继中选出最大者
  List_iterator<T> selectMax(List_iterator<T> p, rank n) const;
  List_iterator<T> selectMax() const { return selectMax(header->succ, _size); }

  // 可写访问接口
  List_iterator<T> insert(List_iterator<T> iter, T const& e) {
    _size++;
    return List_iterator<T>(iter->insertAsSucc(e));
  };  // 将e当作p的后继插入
  List_iterator<T> insert(T const& e, List_iterator<T> iter) {
    _size++;
    return List_iterator<T>(iter->insertAsPred(e));
  };  // 将e当作p的前驱插入

  List_iterator<T> push_front(T const& e) { return insert(header, e); };
  List_iterator<T> push_back(T const& e) { return insert(e, trailer); };

  T pop_back() { return erase(last()); };
  T pop_front() { return erase(first()); };
  T erase(List_iterator<T> p);  // 删除合法位置p处的节点,返回被删除节点

  void merge(List<T>& L) {
    merge(List_iterator<T>(header->succ), _size, L,
          List_iterator<T>(L.header->succ), L._size);
  }                                      // 全列表归并
  void sort(List_iterator<T>, rank);     // 列表区间排序
  void sort() { sort(first(), _size); }  // 列表整体排序

  rank dedup();     // 无序去重
  rank uniquify();  // 有序去重

  void reverse();  // 前后倒置（习题）
  // 遍历
  void traverse(void (*)(T&));  // 依次实施visit操作（函数指针）
  template <typename VST>
  void traverse(VST&);  // 依次实施visit操作（函数对象）

 private:
  using special_pos = List_iterator<T>;
  rank _size;
  special_pos header, trailer;  // 规模、头哨兵、尾哨兵

 protected:
  void init();                        // 列表创建时的初始化
  rank clear();                       // 清除所有节点
  void copy(List_iterator<T>, rank);  // 复制列表中自位置p起的n项

  //merge 应当返回merge后list的头迭代器
  List_iterator<T> merge(List_iterator<T>, rank, List<T>&, List_iterator<T>,
                         rank);             // 归并
  void mergeSort(List_iterator<T>&, rank);  // 对从p开始连续的n个节点归并排序
  void selectionSort(List_iterator<T> const,
                     rank);  // 对从p开始连续的n个节点选择排序
  void insertionSort(List_iterator<T>, rank);  // 对从p开始连续的n个节点插入排序
  void radixSort(List_iterator<T>, rank);  // 对从p开始连续的n个节点基数排序
};                                         // List

}  // namespace CYT_DSA

#include "List_impl.hpp"
