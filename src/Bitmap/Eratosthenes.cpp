#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <climits>

#include "Bitmap.hpp"
#include "Bitmap_testcase.hpp"

static const int LIMIT = (int)std::sqrt(INT_MAX);

void Eratothenes(const int n, const bool output, const bool dump) {
  CYT_DSA::Bitmap B(n);
  B.set(0);
  B.set(1);
  for (int i = 2; i * i < n; i++) {
    if (B.test(i) == false) {  // 这是素数
      for (int j = std::min(LIMIT, i) * std::min(LIMIT, i); j <= n; j += i) {
        B.set(j);
      }
    }
  }

  if (output) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
      if (!B.test(i)) {
        std::cout.width(5);
        std::cout << i << ' ';
        cnt++;
        if (cnt % 25 == 0) std::cout << '\n';
      }
    }
    std::cout << "\ntotal : " << cnt << '\n';
  }

  if (dump) {
    std::string filename = "PrimeN_" + std::to_string(n) + ".hex";
    B.dump(filename.c_str());
  }
}