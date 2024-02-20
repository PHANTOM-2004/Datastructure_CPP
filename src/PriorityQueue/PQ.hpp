#pragma once

namespace CYT_DSA {

template <typename T>
class PQ {
 public:
  /*
   * @brief push - 进队
   * @param e 进队元素
   */
  virtual void push(const T& e) = 0;
  /*
   * @brief top - 队首，也就是最大值
   */
  virtual const T& top() const = 0;
  /*
   * @brief push - 出队，也就是弹出最大值
   */
  virtual void pop() = 0;  // 弹出队首
};
}  // namespace CYT_DSA