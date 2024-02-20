#include "Steap.hpp"

#include <iostream>
#include <string>

int main() {
  using namespace CYT_DSA;
  if (1) {
    constexpr int N = 20;
    Steap<int> stp, tmp;
    for (int i = 0; i < N; i++) {
      stp.push(rand() % 40);
    }
    for (int i = 0; i < N; i++) {
      std::cout << "round " + std::to_string(i) << '\n';
      std::cout << "cur_stack : \n";
      while (stp.size()) {
        int target = stp.stackTop();
        stp.pop();
        tmp.push(target);
        std::cout << target << ' ';
      }
      while (tmp.size()) {
        stp.push(tmp.stackTop());
        tmp.pop();
      }
      std::cout << '\n';
      std::cout << "cur_stack_max : ";
      std::cout << stp.top() << '\n';
      stp.pop();
    }
  }

  return 0;
}