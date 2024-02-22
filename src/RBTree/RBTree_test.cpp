#include "RBTree.hpp"

#include "TestCommon.hpp"
#include "Test_BinTree.hpp"

int main() {
  using namespace CYT_DSA;
  using namespace tools;
  if (1) {
    msg("insert");
    RBTree<int> T;
    constexpr auto N = 20;
    for (int i = 0; i < N; i++) {
      T.insert(i);
      printBT(&T);
    }
    msg("insert", 0);
  }
  if (1) {
    msg("remove");
    RBTree<int> T;
    constexpr auto N = 50;
    for (int i = 0; i < N; i++) {
      T.insert(rand()%(2*N));
      //printBT(&T);
      std::cout.flush();
    }
    printBT(&T);
    for (int i = 0; i < N; i++) {
      T.remove(i);
      printBT(&T);
    }
    msg("remove", 0);
  }
  return 0;
}
