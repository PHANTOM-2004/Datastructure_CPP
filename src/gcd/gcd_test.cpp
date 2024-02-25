#include "gcd.hpp"

#include <iostream>
#include <chrono>
using namespace CYT_DSA;

constexpr bool show_ans = false;

class GCDTest {
  int a, b;
  bool pass = false;
  static constexpr int MOD = 1000;
  void output() {
    if (pass) {
      if (show_ans) printf("---%4d %4d pass---\n", a, b);
    } else {
      printf("xxxx%4d%4d failxxxx\n", a, b);
      printf("fail case : %4d %4d, ans : % 4d, test1 : %4d test2 % 4d\n", a, b,
             GCD::gcd1(a, b), GCD::gcd2(a, b), GCD::gcd3(a, b));
      getchar();
    }
  }
  void test() {
    auto ans = GCD::gcd1(a, b);
    auto t2 = GCD::gcd2(a, b);
    auto t3 = GCD::gcd3(a, b);
    pass = t2 == ans && t3 == ans;
  }

 public:
  void generate_test() {
    a = rand() % MOD;
    b = rand() % MOD;
    if (show_ans) {
      printf("%3d % 3d\n", a, b);
      fflush(stdout);
    }
    test();
    output();
  }
};

int main() {
  GCDTest T;
  using namespace std::chrono;
  constexpr int N = 20000000;
  const auto begin = high_resolution_clock::now();
  for (int i = 0; i < N; i++) {
    if (show_ans) printf("case %3d : ", i);
    T.generate_test();
  }
  const auto end = high_resolution_clock::now();
  const auto duration = duration_cast<microseconds>(end - begin);
  std::cout << (duration.count() * 1.0 / 1000000) << " seconds\n";
  std::cout << "average : " << duration.count() * 1.0 / N / 2<< " us\n";
}