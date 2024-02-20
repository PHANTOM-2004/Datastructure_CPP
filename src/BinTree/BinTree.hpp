#pragma once
#define MY_TEST

#include "BiTNode.hpp"

namespace CYT_DSA {
template <typename T>
class BinTree {  // 二叉树模板类

 public:
  BinTree() = default;
  ~BinTree() {
#ifdef MY_TEST
    std::cout << "\n**destroying BinTree**\n";
    if (0 < _size) {
      std::cout << "Tree size : " << _size << "; ";
      std::cout << remove(_root) << " Nodes deleted\n";
    }
    std::cout << "**BinTree destroyed**\n";
#else
    if (0 < _size) remove(_root);
#endif
  }

  int size() const { return _size; }      // 规模
  bool empty() const { return !_root; }   // 判空
  BPtr<T> root() const { return _root; }  // 树根
  BPtr<T>& fromroot() { return this->_root; }
  BPtr<T> insert(T const&);  // 将e当作根节点插入空的二叉树
  BPtr<T> insert(T const&, BPtr<T>);      // 插入左孩子
  BPtr<T> insert(BPtr<T>, T const&);      // 插入右孩子
  BPtr<T> attach(BinTree<T>*&, BPtr<T>);  // 接入左子树
  BPtr<T> attach(BPtr<T>, BinTree<T>*&);  // 接入右子树
  int remove(BPtr<T>);                    // 子树删除
  BinTree<T>* secede(BPtr<T>);            // 子树分离

  template <typename VST>  // 操作器
  void travLevel(VST& visit) {
    if (_root) _root->level_traverse(visit);
  }                        // 层次遍历
  template <typename VST>  // 操作器
  void travPre(VST& visit) {
    if (_root) _root->pre_traverse(visit);
  }                        // 先序遍历
  template <typename VST>  // 操作器
  void travIn(VST& visit) {
    if (_root) _root->in_traverse(visit);
  }                        // 中序遍历
  template <typename VST>  // 操作器
  void travPost(VST& visit) {
    if (_root) _root->post_traverse(visit);
  }                        // 后序遍历
  template <typename VST>  // 操作器
  void traverse(VST&);     // 自定义遍历

  // 比较器（其余自行补充）
  bool operator<(BinTree<T> const& t) const;
  bool operator==(BinTree<T> const& t) const;
  bool operator>(BinTree<T> const& t) const;
  bool operator!=(BinTree<T> const& t) const;
  bool operator<=(BinTree<T> const& t) const;
  bool operator>=(BinTree<T> const& t) const;

 protected:
  int _size = 0;
  BPtr<T> _root = nullptr;              // 规模、根节点
  virtual int updateHeight(BPtr<T> x);  // 更新节点x的高度
  void updateHeightAbove(BPtr<T> x);    // 更新节点x及其祖先的高度
  constexpr BPtr<T>& FromParentTo(BPtr<T> x) {
    return x == _root ? _root
                      : (IsLChild(x) ? x->parent->left : x->parent->right);
  } /*将 const
 属性移除后，返回类型就匹配了。这是因为在原始的代码中，你的函数声明是 BPtr<T>
 FromParentTo(BPtr<T> x) const，其中的 const 修饰了整个成员函数。

 当你调用成员函数时，会默认应用到 this
 指针上，即成员函数所属的对象。因此，在成员函数内部，所有成员变量都被视为
 const，包括 _root。由于 _root 是一个 const指针，条件运算符的两个分支的
 返回类型也必须匹配。在条件运算符中，为了保持类型一致性，需要返回一个const
 指针。

 但是，如果你移除了函数声明中的 const 修饰符，那么函数就不再是 const
 成员函数，this 指针不再隐式地被视为 const。因此，成员变量 _root 也不再是
 const，可以正常返回非 const 指针。*/

};  // BinTree

}  // namespace CYT_DSA

#include "BinTree_impl.hpp"