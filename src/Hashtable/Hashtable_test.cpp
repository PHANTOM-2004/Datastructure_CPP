#include "Hashtable.hpp"

#include <iostream>
#include <vector>

#include "TestCommon.hpp"

int main() {
  using namespace CYT_DSA;

  if (1) {
    msg("capacity");
    Hashtable<int, int> T(2004);
    std::cout << T.capacity();
    msg("capacity", 0);
  }
  if (1) {
    using pkv = std::pair<int, int>;
    msg("put");
    Hashtable<int, int> T(100);
    std::vector<pkv> T_put;
    constexpr int N = 20;
    for (int i = 0; i < N; i++) {
      auto k = rand();
      auto v = rand();
      T.put(k, v);
      T_put.push_back(std::make_pair(k, v));
    }
    for (int i = 0; i < N; i++) {
      auto &kv = T_put[i];
      std::cout << "key : " << kv.first << " val : " << kv.second << '\n';
      std::cout << "Ans : ";
      auto &res = *T.get(kv.first);
      std::cout << res << "------" << (res == kv.second) << '\n';
    }
    std::cout << "final size : " << T.size() << '\n';
    std::cout << "final capacity : " << T.capacity() << '\n';
    msg("put", 0);
  }

  if (1) {
    using pkv = std::pair<long long int, int>;
    msg("rehash");
    Hashtable<long long int, int> T(30);
    std::vector<pkv> T_put;
    constexpr int N = 40;
    for (int i = 0; i < N; i++) {
      auto k = rand() * ((unsigned long long)1e9 + 7ull);
      auto v = rand();
      T.put(k, v);
      T_put.push_back(std::make_pair(k, v));
    }
    for (int i = 0; i < N; i++) {
      auto &kv = T_put[i];
      std::cout << "key : " << kv.first << " val : " << kv.second << '\n';
      std::cout << "Ans : ";
      auto &res = *T.get(kv.first);
      std::cout << res << "------" << (res == kv.second) << '\n';
    }
    std::cout << "final size : " << T.size() << '\n';
    std::cout << "final capacity : " << T.capacity() << '\n';
    msg("rehash", 0);
  }

  if (1) {
    using pkv = std::pair<long long, int>;
    msg("remove");
    Hashtable<long long, int> T(10);
    std::vector<pkv> T_put;
    constexpr int N = 40;
    for (int i = 0; i < N; i++) {
      auto k = rand() * ((unsigned long long)1e9 + 7ull);
      auto v = rand();
      T.put(k, v);
      T_put.push_back(std::make_pair(k, v));
    }
    for (int i = 0; i < N; i++) {
      auto &kv = T_put[i];
      std::cout << "key : " << kv.first << " val : " << kv.second << '\n';
      T.remove(kv.first);
      std::cout << "after removed Ans : ";
      bool res = (T.get(kv.first) == nullptr);
      std::cout << "------" << res << '\n';
    }
    std::cout << "final size : " << T.size() << '\n';
    std::cout << "final capacity : " << T.capacity() << '\n';
    msg("remove", 0);
  }

  if (1) {
  }
  return 0;
}