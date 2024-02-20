#include "Queue.hpp"

#include <iostream>

#include "TestCommon.hpp"

int main() {
  using namespace CYT_DSA;
  List<std::string> v;
  Queue<std::string> Q;
  const std::string s[] = {"123asd", "askdjh18xsbja", "asuiydg1", "asdjk12asd"};
  for (auto &iter : s) {
    Q.push_back(iter);
    std::cout << iter << std::endl;
  }

  Q.traverse(show);
  std::cout << std::endl;
  while (Q.empty() == false) {
    std::cout << Q.pop_front() << " -> ";
  }

  return 0;
}