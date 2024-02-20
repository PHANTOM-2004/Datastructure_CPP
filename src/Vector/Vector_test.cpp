#include "Vector.hpp"

#include <iostream>
#include <vector>

#include "TestCommon.hpp"

constexpr bool ON = 1;
int main() {
  using namespace CYT_DSA;
  using std::cout;
  using std::endl;
  std::cout << "Vector test begin:\n\n";

  const std::string A[] = {std::string("asdasf"),
                           std::string("fuckyou"),
                           "1023asd",
                           "dayanganzuilisai",
                           "askjdhasd",
                           "asldjkhasldjk",
                           "wqoieucdsnjca"};
  const std::string *const A_ptr[] = {A, A + 1, A + 2, A + 3, A + 4, A + 5};
  // test case 1
  if (ON) {
    msg("constructor");

    Vector<int> v1(25, 9, 3);
    Vector<int> v2(v1);
    v1.traverse(show);
    v2.traverse(show);

    Vector<std::string> v3(A, 2);
    v3.traverse(show);

    Vector<std::string> v4(v3);
    v4.traverse(show);

    Vector<std::string> v5(A, 2, 5);
    v5.push_back(A[0]);
    v5.traverse(show);

    double r(9.22);
    Vector<double *> v6(&r, 5, 2);
    v6.traverse(show);
    const int a[6] = {1, 23, 1, 23};

    std::string str;
    Vector<std::string *> v7;
    v7.push_back(&str);
    v7.traverse(show);

    using type = const std::string **;
    Vector<std::string *> v8((std::string *const *)A_ptr, 5);
    v8.traverse(show);

    msg("constructor", 0);
  }
  // test case 2
  if (ON) {
    msg("insert/delete");
    Vector<std::string> v1(A, 6);
    v1.traverse(show);
    v1.insert(1, "pos_1");
    v1.push_back("chenruitong");
    v1.push_back("chenruitong");

    v1.pop_front();
    v1.traverse(show);
    cout << endl;

    v1.push_back("chenjiaqing");
    v1.push_back("chenjiaqing");
    v1.push_front("sunzhicheng");
    v1.pop_back();
    v1.traverse(show);
    cout << endl;

    v1.erase(0, 3);
    v1.traverse(show);
    msg("insert/delete", 0);
  }
  if (ON) {
    msg("dedup");
    Vector<double> v2;
    for (int i = 0; i < 15; i++) {
      v2.push_back(i);
    }
    v2.traverse(show);
    v2.unsort();
    v2.traverse(show);
    v2.clear();

    for (int i = 0; i < 15; i++) {
      v2.push_back(i);
      v2.push_back(i);
    }
    v2.traverse(show);
    v2.dedupilicate();
    v2.traverse(show);

    msg("dedup", 0);
  }
  if (ON) { // uniquify
    msg("unique");
    Vector<long long> v2;
    for (int i = 0; i < 20; i++) {
      v2.push_back(i);
      v2.push_back(i);
    }
    v2.traverse(show);
    cout << endl;
    v2.uniquify();
    v2.traverse(show);
    cout << endl;
    msg("unique", 0);
  }

  if (ON) { // search
    msg("search");
    Vector<long long> v2;
    for (int i = 0; i < 1500; i++) {
      v2.push_back(i);
      v2.push_back(i);
    }
    v2.traverse(show);
    std::cout << v2.search(4) << '\n';
    std::cout << v2.search(400) << '\n';
    msg("search", 0);
  }

  if (ON) { // function like
    msg("func_type");
    struct increase {
      int operator()(int &T) const { return ++T; }
    };
    Vector<int> v1;
    for (int i = 0; i < 15; i++) {
      v1.push_back(i);
      v1.push_back(i);
    }
    v1.traverse(show);
    v1.traverse(increase());
    v1.traverse(show);
    msg("func_type", 0);
  }

  if (ON) { // function like
    msg("max_pos");
    struct increase {
      int operator()(int &T) const { return ++T; }
    };
    Vector<int> v1;
    for (int i = 0; i < 15; i++) {
      auto e = rand() % 50;
      v1.push_back(e);
      v1.push_back(e);
    }
    v1.traverse(show);
    cout << endl;
    cout << v1.max_pos() << endl;

    msg("max_pos", 0);
  }

#if 1
  if (ON) { // sort
    msg("sort test");
    constexpr int L = 40;
    long long arr[L]{};
    for (int i = 0; i < L; i++)
      arr[i] = rand() % L;
    Vector<long long> v1(arr, L);
    v1.traverse(show);
    v1.sort();
    v1.traverse(show);
    msg("sort test", 0);
  }
#endif
  std::cout << "Vector test end  .\n";
  std::cout << "中文测试\n";
  return 0;
}