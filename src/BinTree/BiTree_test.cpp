#include <iostream>

#include "BinTree.hpp"
#include "TestCommon.hpp"
#include "Test_BinTree.hpp"

static auto shower = [](const int& x) { std::cout << x << ' '; };

template <typename T>
void trav(CYT_DSA::BinTree<T>* Tree) {
  std::cout << "Preorder traverse\n";
  Tree->travPre(shower);
  std::cout << '\n';
  std::cout << "Inorder traverse\n";
  Tree->travIn(shower);
  std::cout << '\n';
  std::cout << "Postorder traverse\n";
  Tree->travPost(shower);
  std::cout << '\n';
  std::cout << "Levelorder traverse\n";
  Tree->travLevel(shower);
  std::cout << '\n';
}

int main() {
  using namespace CYT_DSA;
  using std::cout;
  using std::endl;
  if (1) {
    BinTree<int> bt;
    constexpr int h = 2;
    bt.insert(dice(h * h * h));
    tools::printTree(bt.root());
    tools::randomBinTree(bt, bt.root(), h);
    tools::printTree(bt.root());
    bt.travLevel(shower);
  }

  if (1) {
    msg("build tree/secede");
    using namespace tools;
    BinTree<int> bt;
    constexpr int h = 5;
    bt.insert(dice(h * h * h));
    printBT(&bt);
    tools::randomBinTree(bt, bt.root(), h);
    printBT(&bt);
    bt.travLevel(shower);

    auto posi1 = randomPosiInBinTree(bt.root());
    std::cout << "choose posi : " << posi1->data << '\n';
    auto subtree1 = bt.secede(posi1);
    std::cout << "after secede : \n";
    printBT(&bt);
    printBT(subtree1);

    auto posi2 = randomPosiInBinTree(bt.root());
    std::cout << "choose posi : " << posi2->data << '\n';
    auto subtree2 = bt.secede(posi2);
    std::cout << "after secede : \n";
    printBT(&bt);
    printBT(subtree2);

    auto posi3 = randomPosiInBinTree(bt.root());
    std::cout << "choose posi : " << posi3->data << '\n';
    auto subtree3 = bt.secede(posi3);
    std::cout << "after secede : \n";
    printBT(&bt);
    printBT(subtree3);
    msg("build tree/secede", 0);
  }
  if (1) {
    using namespace tools;
    msg("remove");
    BinTree<int> T;
    constexpr int h = 6;
    T.insert(dice(h * h * h));
    printBT(&T);

    while (T.size() <= 1) {
      tools::randomBinTree(T, T.root(), h);
    }

    printBT(&T);
    auto round = 0;
    while (T.size()) {
      round++;
      const auto pos = randomPosiInBinTree(T.root());
      std::cout << " round : " << round << " choose " << pos->data << '\n';
      T.remove(pos);
      printBT(&T);
    }

    msg("remove", 0);
  }

  if (1) {
    using namespace tools;
    msg("traverse");
    BinTree<int> T;
    constexpr int h = 6;
    T.insert(dice(h * h * h));
    tools::randomBinTree(T, T.root(), h);
    printBT(&T);

    trav(&T);
    msg("traverse", 0);
  }

  return 0;
}