#pragma once

//#define __STRETCH_DEBUG__ 1

#if __STRETCH_DEBUG__
#include "../TestCommon/Test_BinTree.hpp"
#endif

/*不能对根节点施加*/
namespace CYT_DSA {
template <typename T>
void BST<T>::stretchByZag(BPtr<T>& x) {
  /*这里node如果是引用会出错，？*/ /*这里有点问题需要一个临时变量*/
  BPtr<T> node = x;
  if (node == nullptr || HasChild(node) == false) return;
  int h = 0;
  BPtr<T> last_node = node;
  while (last_node->right != nullptr) last_node = last_node->right;
  while (node->left != nullptr) node = node->left;
  node->height = h++;
  /*x是第一个节点，要用node替代x*/ /*wrong*/
  /*这里x = last_node应该是不对的，这里会直接改变x指针，实际上并不需要赋值*/
  for (/*x = node*/; node != last_node; node = node->parent, node->height = h++) {
    while (HasRChild(node)) {
#if __STRETCH_DEBUG__
      std::cout << "curnode : data : " << node->data << "  address : " << node
                << '\n';
#endif
      node->zag();
#if __STRETCH_DEBUG__
      std::cout << "curnode : data : " << node->data << "  address : " << node
                << '\n';
      tools::printBT(this);
      getchar();
#endif
    }
  }
  if (x == this->_root) this->_root = last_node;
}

template <typename T>
void BST<T>::stretchByZig(BPtr<T>& x) {
  BPtr<T> node = x;
  if (node == nullptr || HasChild(node) == false) return;

  int h = 0;
  BPtr<T> last_node = node;
  while (last_node->left != nullptr) last_node = last_node->left;
  while (node->right != nullptr) node = node->right;
  node->height = h++;

  /*这里x = last_node应该是不对的，这里会直接改变x指针，实际上并不需要赋值*/
  for (/*x = last_node*/; node != last_node; node = node->parent, node->height = h++) {
    while (HasLChild(node)) {
#if __STRETCH_DEBUG__
      std::cout << "curnode : data : " << node->data << "  address : " << node
                << '\n';
#endif
      node->zig();
#if __STRETCH_DEBUG__
      std::cout << "curnode : data : " << node->data << "  address : " << node
                << '\n';
      tools::printBT(this);
      getchar();
#endif
    }
  }
  if (x == this->_root) this->_root = last_node;
}
}  // namespace CYT_DSA