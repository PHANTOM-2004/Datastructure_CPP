#include "BST.hpp"

#include <iostream>

#include "TestCommon.hpp"
#include "Test_BinTree.hpp"

int main() {
  if (1) {
    msg("insert");
    using namespace CYT_DSA;
    using namespace tools;
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
    }
    printBT(&test1);

    BST<double> test2;
    test2.insert(29);
    printBT(&test2);
    for (int i = 0; i < N; i++) test2.insert(rand() % 50);
    printBT(&test2);
    msg("insert", 0);
  }

  if (1) {
    msg("remove");
    using namespace CYT_DSA;
    using namespace tools;
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      test1.insert(rand() % 20);
    }
    printBT(&test1);
    test1.remove(3);
    printBT(&test1);
    getchar();
    for (int i = N / 2; i >= 0; i--) {
      test1.remove(i);
      std::cout << "Remove node : " << i << '\n';
      printBT(&test1);
    }
    msg("remove", 0);
  }

  if (1) {
    msg("search");
    using namespace CYT_DSA;
    using namespace tools;
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      test1.insert(rand() % 20);
    }
    printBT(&test1);
    for (int i = N / 2; i >= 0; i--) {
      auto res = test1.search(i);
      std::cout << "Search node : " << i << '\n';
      std::cout << "Search result : " << res->data << '\n';
    }
    msg("search", 0);
  }

  if (1) {
    using namespace tools;
    msg("zag");
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      test1.insert(rand() % 20);
    }
    printBT(&test1);
    std::cout << "root : " << test1.root()->data << '\n';
    test1.root()->lChild()->zag();
    // test1.root()->zag();
    printBT(&test1);
    msg("zag", 0);
  }

  if (1) {
    using namespace tools;
    msg("zig");
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      test1.insert(rand() % 20);
    }
    printBT(&test1);
    std::cout << "root : " << test1.root()->data << '\n';
    test1.root()->rChild()->zig();
    // test1.root()->zag();
    printBT(&test1);
    msg("zig", 0);
  }

  if (1) {
    using namespace tools;
    msg("stretch");
    BST<int> test1;
    test1.insert(4);
    printBT(&test1);
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      test1.insert(i);
      test1.insert(rand() % 20);
    }
    printBT(&test1);
    std::cout << "root : " << test1.root()->data << '\n';
    // BiTNode<int>::stretchByZag(test1.root()->left);
#if 1
    test1.stretchByZag(test1.root()->lChild());
    // test1.root()->zag();
    printBT(&test1);
    test1.stretchByZig(test1.root()->rChild());
    printBT(&test1);

    test1.stretchByZag(test1.fromroot());
    printBT(&test1);

    test1.stretchByZig(test1.fromroot());
    printBT(&test1);
#endif
    msg("stretch", 0);
  }

  return 0;
}