#include "Queap.hpp"

#include <iostream>
#include <string>

static auto show = [](int& p) { std::cout << p << ' '; };

int main() {
  using namespace CYT_DSA;
  if (1) {
    constexpr int N = 20;
    Queap<int> stp, tmp;
    for (int i = 0; i < N; i++) {
      auto target = rand() % 100;
      std::cout << target << "<--";
      stp.push(target);
    }
    std::cout << "\n";
    for (int i = 0; i < N; i++) {
      std::cout << "round " + std::to_string(i) << '\n';
      std::cout << "cur_queue : \n";
      while (stp.size()) {
        int target = stp.front();
        stp.pop();
        tmp.push(target);
        std::cout << target << ' ';
      }
      while (tmp.size()) {
        stp.push(tmp.front());
        tmp.pop();
      }
      std::cout << '\n';
      std::cout << "cur_queue_max : ";
      std::cout << stp.top() << '\n';
      stp.pop();
    }
  }

}