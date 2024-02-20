#include "primeNLT.hpp"

namespace Prime {
int primeNLT(int c, const int n, const char* const filename) {
  using namespace CYT_DSA;
  Bitmap B(filename, n);
  while (c < n) {
    if (B.test(c))
      c++;
    else
      return c;
  }
  return n;
}
}
