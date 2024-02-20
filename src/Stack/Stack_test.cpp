#include "Stack.hpp"

#include <iostream>

#include "TestCommon.hpp"

int main() {
  using namespace CYT_DSA;
  Vector<std::string> v;
  Stack<std::string> stk;
  const std::string s[] = {"123asd", "askdjh18xsbja", "asuiydg1", "asdjk12asd"};
  for (auto& iter : s) {
    stk.push(iter);
    std::cout << iter << std::endl;
  }

  stk.traverse(show);
  auto p = [](std::string& r) { std::cout << r << ' '; };
  std::cout << std::endl;
  stk.traverse(p);
  while (stk.empty() == false) {
    std::cout << stk.pop() << " -> ";
  }
  return 0;
}