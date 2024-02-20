#include "Splay.hpp"

#include "TestCommon.hpp"
#include "Test_BinTree.hpp"

int main() {
  using namespace tools;
  using namespace CYT_DSA;
  if (0) {
    Splay<int> T;
    // T.insert(9);
    printBT(&T);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      T.insert(i);
      printBT(&T);
    }
  }

  if (0) {
    Splay<int> T;
    // T.insert(9);
    printBT(&T);
    constexpr int N = 10;
    for (int i = N; i > 0; i--) {
      T.insert(i);
      printBT(&T);
    }
  }

  if (1) {
    msg("search");
    Splay<int> T;
    // T.insert(9);
    constexpr int N = 10;
    T.insert(N / 2);
    for (int i = 0; i < N; i++) {
      T.insert(i);
      // printBT(&T);
    }
    printBT(&T);

    for (int i = 0; i < N; i++) {
      T.search(i);
      printBT(&T);
    }
    msg("search", 0);
  }

  if (1) {
    msg("delete");
    Splay<int> T;
    // T.insert(9);
    constexpr int N = 10;
    T.insert(N / 2);
    for (int i = 0; i < N; i++) {
      T.insert(i);
      // printBT(&T);
    }
    printBT(&T);
    for (int i = 0; i < N; i++) {
      T.remove(i);
      printBT(&T);
    }
    msg("delete", 0);
  }
  return 0;
}