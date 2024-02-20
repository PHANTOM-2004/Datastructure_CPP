#include "List.hpp"

#include <iostream>

#include "TestCommon.hpp"
using std::cout;
using std::endl;

constexpr bool ON = 1;

int main() {
  using namespace CYT_DSA;
  std::cout << "Test begin\n";

  if (ON) {  // test basic init
    msg("basic init");
    List<int> L1;
    constexpr int L = 15;
    for (int i = 0; i < L; i++) L1.push_back(rand() % 200);
    for (int i = 0; i < L; i++) L1.push_front(rand() % 200);
    L1.traverse(show);
    cout << endl << L1.size() << endl;

    for (int i = 0; i < L / 5; i++) {
      L1.pop_back();
      L1.pop_front();
    }
    L1.traverse(show);
    cout << endl;
    std::cout << L1.size() << endl;
    msg("basic init", 0);
  }

  if (ON) {  // test copy init
    msg("copy init");
    List<int> L1;
    constexpr int L = 15;
    for (int i = 0; i < L; i++) L1.push_back(rand());
    L1.traverse(show);
    cout << endl;

    List<int> L2(L1);
    L2.traverse(show);
    cout << endl;

    List<int> L3(L1.first(), 10);
    L3.traverse(show);
    cout << endl;

    List<int> L4(L1, 3, 10);
    L4.traverse(show);
    cout << endl;
    msg("copy init", 0);
  }

  if (ON) {
    msg("dedup");
    List<int> L1;
    constexpr int L = 20;
    for (int i = 0; i < L; i++) {
      auto e = rand() % 200;
      L1.push_back(e);
      L1.push_back(e);
    }
    L1.traverse(show);
    cout << endl;

    auto r = L1.dedup();
    L1.traverse(show);
    cout << "\ndelete : " << r << endl;
    msg("dedup", 0);
  }
  if (ON) {
    msg("unique");
    List<int> L1;
    constexpr int L = 15;
    for (int i = 0; i < L; i++) {
      auto e = i * 3;
      L1.push_back(e);
      L1.push_back(e);
    }
    L1.traverse(show);
    cout << endl;

    auto r = L1.uniquify();
    L1.traverse(show);
    cout << "\ndelete : " << r << endl;
    msg("unique", 0);
  }

  if (ON) {
    msg("search");
    List<int> L1;
    constexpr int L = 10;
    auto target = 0;
    for (int i = 0; i < L; i++) {
      // auto e = rand() % 200;
      auto e = i * 5;
      L1.push_back(e);
      L1.push_back(e);
      L1.push_back(e);
      if (i == L / 2) target = e - 1;
    }
    L1.traverse(show);
    cout << endl;

    target = -10;
    auto res = L1.search(target);
    std::cout << "target : " << target << " find: " << *res
              << " valid : " << L1.valid(res) << endl;
    msg("search", 0);
  }
  if (ON) {
    msg("merge");
    List<int> L1, L2;
    constexpr int L = 10;
    for (int i = 0; i < L; i++) {
      L1.push_back(i);
      L2.push_back(i + 2);
    }
    L1.traverse(show);
    cout << endl;

    L2.traverse(show);
    cout << endl;

    L1.merge(L2);
    L1.traverse(show);
    cout << endl;

    msg("merge", 0);
  }

  if (ON) {
    msg("sort");
    List<int> L1;
    constexpr int L = 20;
    for (int i = 0; i < L; i++) {
      auto e = rand() % 200;
      L1.push_back(e);
      L1.push_back(e);
    }
    L1.traverse(show);
    cout << endl;

    L1.sort();
    L1.traverse(show);
    std::cout << "\ntotal : " << L1.size() << endl;
    msg("sort", 0);
  }

  if (ON) {
    msg("reverse");
    List<int> L1;
    constexpr int L = 10;
    for (int i = 0; i < L; i++) {
      auto e = i * 3;
      L1.push_back(e);
      L1.push_back(e);
    }
    L1.traverse(show);
    cout << endl;
    L1.reverse();
    L1.traverse(show);
    cout << endl;
    L1.reverse();
    L1.traverse(show);
    cout << endl;
    msg("reverse", 0);
  }
#if 0
#endif
  cout << "Test end\n";
  return 0;
}