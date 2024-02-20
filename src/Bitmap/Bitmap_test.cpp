#include <iostream>

#include "Bitmap_testcase.hpp"

int main() {
  using namespace CYT_DSA;
  constexpr int size = 64;
  Bitmap bmp(size);

  std::string cmp;
  cmp.resize(size, '0');

  for (int i = 0; i < size / 4; i++) {
    auto pos = rand() % size;
    // std::cout << "pos : " << pos << "  ";
    bmp.set(pos);
    cmp[pos] = '1';
  }
  std::cout << std::endl;
  std::cout << "Ans  : " << cmp << '\n';
  std::cout << "Test : " << bmp.to_string(bmp.size()) << '\n';
  bmp.dump("bmptest1.hex");

  Eratothenes(1000, 1);
  constexpr int MAXN = 1048576;
  Eratothenes(MAXN, 0, 1);
  return 0;
}