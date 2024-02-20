#include <iostream>

#include "PQ_CompleteHeap.hpp"
#include "TestCommon.hpp"
using namespace CYT_DSA;

template <typename T>
using PQT = PQ_CH<T>;

void test() {
  if (1) {
    msg("push/pop");
    PQT<int> T1;
    constexpr int N = 30;
    for (int i = 0; i < N; i++) {
      auto target = rand() % 40;
      std::cout << target << ' ';
      T1.push(target);
    }
    std::cout << "\n";
    for (int i = 0; i < N; i++) {
      std::cout << T1.top() << ' ';
      T1.pop();
    }
    std::cout << '\n';
    msg("push/pop", 0);
  }

  if (1) {
    msg("floyd");
    constexpr int N = 40;
    int A[N] = {0};
    for (int i = 0; i < N; i++) {
      auto target = rand() % 40;
      A[i] = target;
    }
    PQT<int> T1(A, N);
    for (int i = 0; i < N; i++) {
      std::cout << T1.top() << ' ';
      T1.pop();
    }
    std::cout << '\n';
    msg("floyd", 0);
  }
}

int main() {
  test();
  return 0;
}