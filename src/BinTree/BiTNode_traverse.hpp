#pragma once

#include "../Queue/Queue.hpp"
#include "../Stack/Stack.hpp"

namespace CYT_DSA {

template <typename T>
BPtr<T> BiTNode<T>::succ() const {
  //auto ptr = const_cast<BPtr<T> >(this);
  const BiTNode<T>* ptr = this;
  if (HasRChild(ptr)) {
    ptr = ptr->right;
    while (HasLChild(ptr)) {
      ptr = ptr->left;
    }
  } else {
    while (IsRChild(ptr)) ptr = ptr->parent;
    ptr = ptr->left;
  }
  return const_cast<BPtr<T> >(ptr);
}

/*******************************************************************************
 * inorder traverse
 *
 *
 *
 *
 *******************************************************************************/
template <typename T, typename func_type>
static void in_traverse_R(BPtr<T> x, func_type& func) {
  if (x == nullptr) return;
  in_traverse_R<T, func_type>(x->lChild(), func);
  func(x->data);
  in_traverse_R<T, func_type>(x->rChild(), func);
}

template <typename T>
static void GoAlongVine(BPtr<T> x, Stack<BPtr<T>>& stk) {
  while (x != nullptr) {
    stk.push(x);
    x = x->lChild();
  }
}

template <typename T, typename func_type>
static void in_traverse_I1(BPtr<T> x, func_type& func) {
  Stack<BPtr<T>> S;
  while (true) {
    GoAlongVine(x, S);
    if (S.empty()) break;
    x = S.pop();
    func(x->data);
    x = x->rChild();
  }
}

template <typename T, typename func_type>
static void in_traverse_I2(BPtr<T> x, func_type& func) {
  Stack<BPtr<T>> S;
  while (true) {
    if (x != nullptr) {
      S.push(x);
      x = x->lChild();
    } else if (S.size()) {
      x = S.pop();
      func(x->data);
      x = x->rChild();
    } else
      break;
  }
}

template <typename T, typename func_type>
static void in_traverse_I3(BPtr<T> x, func_type& func) {
  bool backtraced = false;
  while (true) {
    if (HasLChild(x) && backtraced == false) {
      x = x->lChild();
    } else if (HasRChild(x)) {
      func(x->data);
      x = x->rChild();
      backtraced = false;
    } else {
      func(x->data);
      if ((x = x->succ()) == nullptr) break;
      backtraced = true;
    }
  }
}

template <typename T>
template <typename func_type>
void BiTNode<T>::in_traverse(func_type& func) {
  constexpr int opt = 2;
  switch (opt) {
    case 0:
      in_traverse_R<T, func_type>(this, func);
      break;
    case 1:
      in_traverse_I1<T, func_type>(this, func);
      break;
    case 2:
      in_traverse_I2<T, func_type>(this, func);
      break;
    case 3:
      in_traverse_I3<T, func_type>(this, func);
      break;
  }
}

/*******************************************************************************
 * preorder traverse
 *
 *
 *
 *
 *******************************************************************************/

template <typename T, typename func_type>
static void VisAlongVine(BPtr<T> x, func_type& func, Stack<BPtr<T>>& stk) {
  while (x != nullptr) {
    func(x->data);
    stk.push(x->rChild());
    x = x->lChild();
  }
}

template <typename T, typename func_type>
static void pre_traverse_I1(BPtr<T> x, func_type& func) {
  if (x == nullptr) return;

  Stack<BPtr<T>> stk;
  stk.push(x);
  while (stk.size()) {
    x = stk.pop();
    func(x->data);
    if (HasRChild(x)) stk.push(x->rChild());
    if (HasLChild(x)) stk.push(x->lChild());
  }
}


template <typename T, typename func_type>
static void pre_traverse_I2(BPtr<T> x, func_type& func) {
  Stack<BPtr<T>> stk;
  while (true) {
    VisAlongVine(x, func, stk);
    if (stk.empty()) break;
    x = stk.pop();
  }
}

template <typename T, typename func_type>
static void pre_traverse_R(BPtr<T> x, func_type& func) {
  if (x == nullptr) return;
  func(x->data);
  pre_traverse_R<T, func_type>(x->lChild(), func);
  pre_traverse_R<T, func_type>(x->rChild(), func);
}

template <typename T>
template <typename func_type>
void BiTNode<T>::pre_traverse(func_type& func) {
  constexpr int opt = 1;
  switch (opt) {
    case 0:
      pre_traverse_R<T, func_type>(this, func);
      break;
    case 1:
      pre_traverse_I1<T, func_type>(this, func);
      break;
    case 2:
      pre_traverse_I2<T, func_type>(this, func);
      break;
  }
}

/*******************************************************************************
 * postorder traverse
 *
 *
 *
 *
 *******************************************************************************/
template <typename T>
static void gotoleftmost(Stack<BPtr<T>>& S) {
  BPtr<T> x = nullptr;
  // 这里两种方法是等价的
#if 0
  while ((x = S.top()) != nullptr) {
    if (HasLChild(x)) {
      if (HasRChild(x)) S.push(x->right);
      S.push(x->left);
    } else {
      S.push(x->right);
    }
  }
  S.pop();
#else
  x = S.top();
  while (x != nullptr) {
    if (HasLChild(x)) {
      if (HasRChild(x)) S.push(x->rChild());
      S.push(x = x->lChild());
    } else {
      S.push(x = x->rChild());
    }
  }
  S.pop();
#endif
}

template <typename T, typename func_type>
static void post_traverse_I1(BPtr<T> x, func_type& func) {
  if (x == nullptr) return;
  Stack<BPtr<T>> stk;
  stk.push(x);
  while (!stk.empty()) {
    if (x->Parent() != stk.top()) gotoleftmost(stk);
    x = stk.pop();
    func(x->data);
  }
}

template <typename T, typename func_type>
static void post_traverse_I2(BPtr<T> x, func_type& func) {
  /*仿照leetcode题解风格写出的，刚开始stk也可以不用入栈，
  只需要给while循环加一个条件*/
  if (x == nullptr) return;
  Stack<BPtr<T>> stk;
  BPtr<T> prev = nullptr;
  /*stk.push(x);
  x = x->left;*/

  while (stk.size() || x != nullptr) {
    GoAlongVine(x, stk);
    x = stk.pop();
    if (x->rChild() == nullptr || x->rChild() == prev) {
      func(x->data);
      prev = x;
      x = nullptr;
    } else {
      stk.push(x);
      x = x->rChild();
    }
  }
}


template <typename T, typename func_type>
static void post_traverse_R(BPtr<T> x, func_type& func) {
  if (x == nullptr) return;
  post_traverse_R<T, func_type>(x->lChild(), func);
  post_traverse_R<T, func_type>(x->rChild(), func);
  func(x->data);
}

template <typename T>
template <typename func_type>
void BiTNode<T>::post_traverse(func_type& func) {
  constexpr int opt = 2;
  switch (opt) {
    case 0:
      post_traverse_R<T, func_type>(this, func);
      break;
    case 1:
      post_traverse_I1<T, func_type>(this, func);
      break;
    case 2:
      post_traverse_I2<T, func_type>(this, func);
      break;
  }
}

template <typename T>
template <typename VST>
void BiTNode<T>::level_traverse(VST& func) {
  Queue<BPtr<T>> Q;
  Q.push_back(this);
  while (!Q.empty()) {
    int curlevel_size = Q.size();

    for (int i = 0; i < curlevel_size; i++) {
      auto front = Q.pop_front();
#ifdef MY_TEST
#include <iostream>
      std::cout << ' ';
#endif
      func(front->data);
      if (front->left != nullptr) Q.push_back(front->left);
      if (front->right != nullptr) Q.push_back(front->right);
    }
#ifdef MY_TEST

    std::cout << '\n';
#endif  //  MY_TEST
  }
}

}  // namespace CYT_DSA