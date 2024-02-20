#include "Skiplist.hpp"

#include <iostream>

#include "TestCommon.hpp"

int main() {
  using namespace CYT_DSA;
  if (1) {
    msg("put");
    Skiplist<int, int> L;
    L.put(2, 36);
    L.show();

    L.put(3, 21);
    L.show();

    L.put(4, 99);
    L.show();

    L.put(5, 88);
    L.show();

    L.put(8, 102);
    L.show();

    L.put(6, 666);
    L.show();
    msg("put", 0);
  }

  if (1) {
    msg("put/get");
    Skiplist<int, int> L;
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      L.put(i, rand() % 30);
      L.show();
    }

    for (int i = 0; i < N; i++) {
      std::cout << *L.get(i) << '\n';
      // L.show();
    }
    msg("put/get", 0);
  }

  if (1) {
    msg("remove");
    Skiplist<int, int> L;
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
      L.put(i, rand() % 30);
    }
    L.show();

    for (int i = 0; i < N; i++) {
      L.remove(i);
      L.show();
    }
    msg("remove", 0);
  }

  return 0;
}