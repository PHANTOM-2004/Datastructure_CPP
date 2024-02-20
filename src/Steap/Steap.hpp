#pragma once
#include "PriorityQueue/PQ.hpp"
#include "Stack/Stack.hpp"

namespace CYT_DSA {
template <typename T>
class Steap : public PQ<T> {
 public:
  void push(const T& e) {
    auto target = size() ? std::max(e, this->top()) : e;
#if 0
    std::cout << "size : " << size() << '\t' << target << '\n';
#endif
    // 这里出现一个逆天bug，如果这里不用target进行push，而是直接写
    //  size() ? std::max(e, this->max()) : e，会导致一个问题：
    // push的时候会push进去this->max(),
    // 这是一个对栈顶的引用，e也是一个引用，于是触发了
    //  std::max()对引用的重载版本，这里std::max返回了引用，而CYT_DSA::Stack的底层实现是
    //  CYT_DSA::Vector, push过程中这个引用e传递给CYT_DSA::Vector::push_back(e)
    //  但是push_back的过程中CYT_DSA::Vector会扩容，这导致这个引用失效了
    // 这导致给Vector传参push_back的时候，传进去的e的引用已经失效了，指向的不再是之前的那个内存
    maxstk.push(target);
    origin.push(e);
  }
  void pop() {
    maxstk.pop();
    origin.pop();
  }
  const T& stackTop() const { return origin.top(); }
  const T& top() const { return maxstk.top(); }
  int size() const { return origin.size(); }

 protected:
  Stack<T> origin;
  Stack<T> maxstk;
};
}  // namespace CYT_DSA