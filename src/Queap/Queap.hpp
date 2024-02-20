#pragma once

#include "../PriorityQueue/PQ.hpp"
#include "../Queue/Queue.hpp"

namespace CYT_DSA {
template <typename T>
class Queap : public PQ<T> {
 public:
  void push(const T& e) {
    origin.push_back(e);
    maxque.push_back(e);
    for (auto iter = maxque.last(); iter && *iter <= e; --iter) {
      *iter = e;
    } 
  }
  void pop() {
    origin.pop_front();
    maxque.pop_front();
  }

  const T& front() const { return origin.front(); }
  const T& top() const { return maxque.front(); }
  int size() const { return origin.size(); }

 private:
  Queue<T> origin;
  Queue<T> maxque;
};
}  // namespace CYT_DSA