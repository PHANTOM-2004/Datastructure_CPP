#include "AVL.hpp"

#include <iostream>

#include "TestCommon.hpp"
#include "Test_BinTree.hpp"

int main() {
  std::cout << "yuanshen\n";
  using namespace CYT_DSA;
  using namespace tools;
  if (1) {  // insert
    AVL<int> test1;
    test1.insert(5);
    printBT(&test1);
    constexpr int N = 20;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      // test1.insert(rand() % 20);
      printBT(&test1);
    }
  }
  if (1) {  // remove
    AVL<int> test1;
    test1.insert(5);
    printBT(&test1);
    constexpr int N = 20;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      // test1.insert(rand() % 20);
    }
    printBT(&test1);
    for (int i = 0; i < N; i++) {
      test1.remove(i);
      printBT(&test1);
    }
    if (1) {  // remove
      AVL<int> test1;
      test1.insert(5);
      printBT(&test1);
      constexpr int N = 20;
      for (int i = 0; i < N; i++) {
        test1.insert(i);
        // test1.insert(rand() % 20);
      }
      printBT(&test1);
      test1.stretchByZag();
      printBT(&test1);
      test1.stretchByZig();
      printBT(&test1);
    }
    return 0;
  }
}