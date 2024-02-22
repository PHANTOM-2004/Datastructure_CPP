#pragma once
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "BinTree/BinTree.hpp"
#include "TestCommon.hpp"

namespace tools {
// Binary tree*********************************************************
/**
 * 利用下划线和正反斜杠打印出美观的二叉树，没有破坏二叉树结构，但传入的root会有变化
 * @param root  二叉树根节点
 */
using namespace CYT_DSA;
template <typename T>
std::vector<CYT_DSA::BPtr<T>> inorderTraversal(CYT_DSA::BPtr<T> root) {
  std::vector<CYT_DSA::BPtr<T>> res;
  std::stack<CYT_DSA::BPtr<T>> stk;
  while (root != nullptr || !stk.empty()) {
    while (root != nullptr) {
      stk.push(root);
      root = root->lChild();
    }
    root = stk.top();
    stk.pop();
    res.push_back(root);
    root = root->rChild();
  }
  return res;
}

template <typename T>
void printTree(const CYT_DSA::BPtr<T> root) {
  if (!root) return;
#ifdef __MYDSA__RBTREE_IMPL__
  std::cout << "---RBTree---\n";
#endif
  using namespace CYT_DSA;
  const auto tmp = root;
  std::vector<BPtr<T>> intv = inorderTraversal(tmp);  // 中序遍历节点数组
  std::string template_str;  // 模板string，表示每行打印string的长度
  int location = 0;
  std::unordered_map<BPtr<T>, int>
      first_locations;  // 存储节点对应在本行string中的首位置
  for (const auto &i : intv) {
    location = (int)template_str.size();
    std::string extra = " ";
#ifdef __MYDSA__RBTREE_IMPL__
    extra += i->color() == RBcolor::red ? "R" : "B";
    extra += std::to_string(i->Height());
#endif
    template_str += std::to_string(i->data) + extra;
    first_locations[i] = location;
  }
  for (auto &i : template_str) i = ' ';  // 把模板全部置为空格方便后续使用
  // 层序遍历
  std::queue<BPtr<T>> q;
  q.push(root);
  while (!q.empty()) {
    auto currentLevelSize = q.size();
    int cur_loc = 0;
    std::string tmp_str1 = template_str,
                tmp_str2 = template_str;  // 1为节点所在行，2为其下一行
    for (size_t i = 1; i <= currentLevelSize; ++i) {
      auto node = q.front();
      q.pop();
      cur_loc = first_locations[node];
      std::string num_str = std::to_string(node->data);
#ifdef __MYDSA__RBTREE_IMPL__
      num_str += node->color() == RBcolor::red ? "R" : "B";
      num_str += std::to_string(node->Height());
#endif
      // 左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
      if (node->lChild()) {
        q.push(node->lChild());
        int first_loc = first_locations[node->lChild()] + 1;
        tmp_str2[first_loc++] = '/';
        while (first_loc < cur_loc) tmp_str1[first_loc++] = '_';
      }
      // 中间,对应位置打印节点值（有可能为多位数）
      for (size_t j = 0; j < num_str.length(); ++j, ++cur_loc) {
        tmp_str1[cur_loc] = num_str[j];
      }
      // 右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
      if (node->rChild()) {
        q.push(node->rChild());
        int last_loc = first_locations[node->rChild()] - 1;
        tmp_str2[last_loc] = '\\';
        while (cur_loc < last_loc) {
          tmp_str1[cur_loc++] = '_';
        }
      }
    }
    // 打印两行
    std::cout << tmp_str1 << std::endl;
    std::cout << tmp_str2 << std::endl;
  }
}

template <typename T>
BinNodePosi<T> randomPosiInBinTree(BinNodePosi<T> root) {
  if (!HasChild(root)) return root;
  if (!HasLChild(root))
    return dice(6) ? randomPosiInBinTree(root->rChild()) : root;
  if (!HasRChild(root))
    return dice(6) ? randomPosiInBinTree(root->lChild()) : root;
  return dice(2) ? randomPosiInBinTree(root->lChild())
                 : randomPosiInBinTree(root->rChild());
}

// 随机生成期望高度为h的二叉树
template <typename T>
bool randomBinTree(BinTree<T> &bt, BinNodePosi<T> x, int h) {
  if (0 >= h) return false;  // 至多h层
  if (0 < dice(h))           // 以1/h的概率终止当前分支的生长
    randomBinTree(bt, bt.insert(x, dice((T)h * h * h)), h - 1);
  if (0 < dice(h))  // 以1/h的概率终止当前分支的生长
    randomBinTree(bt, bt.insert(dice((T)h * h * h), x), h - 1);
  return true;
}

template <typename T>
void printBT(const CYT_DSA::BinTree<T> *Tree) {
  using namespace CYT_DSA;
  using namespace tools;
  std::cout << "=====================================\n";
  printTree(Tree->root());
  std::cout << "Tree above size : " << Tree->size() << '\n';
  std::cout << "=====================================\n";
}

}  // namespace tools
