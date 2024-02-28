#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <vector>

constexpr int SEED = 29;

static void generate_sequence(std::vector<int> &t, const int n,
                              const bool reverse = false) {
  t.resize(n);
  if (!reverse)
    for (int i = 0; i < n; i++)
      t[i] = rand();
  else
    for (int i = 0; i < n; i++)
      t[i] = n - i - 1;
}

class SortTest {
  using func_type = std::function<void(int *, int, int)>;
  func_type sort_func;

public:
  SortTest(func_type sort) : sort_func(sort) {}
  double runtest(const int n, const bool reverse = false) {
    srand(SEED);
    std::vector<int> test;
    generate_sequence(test, n, reverse);
    using namespace std::chrono;
    const auto begin = high_resolution_clock::now();
    sort_func(test.data(), 0, n);
    const auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - begin);
    double res = 0;
    std::cout << "Size : " << n
              << " Time : " << (res = duration.count() / 1000.0) << " ms"
              << std::endl;
    return res;
  }
};

static void basic_test(std::function<void(int *, int, int)> sort) {
  static auto print = [](const int elem) { std::cout << elem << ' '; };
  std::vector<int> test{12, 123, 1,    2,     456, 4,  7,      456, 7,
                        89, 4,   7547, 89554, 46,  78, 45,     23,  467,
                        34, 452, 3,    3,     4,   2,  342223, 289, 8954,
                        1,  2,   3,    23,    45,  72, 2,      3,   23};
  std::for_each(test.begin(), test.end(), print);
  std::cout << '\n';
  sort(test.data(), 0, test.size());
  std::for_each(test.begin(), test.end(), print);
  std::cout << '\n';
}

int main() {
  if (1) {
    // std::cout << "bubbleSort" << std::endl;
    // basic_test(bubbleSort<int>);
    // std::cout << "selectionSort" << std::endl;
    // basic_test(selectionSort<int>);
    // std::cout << "insertionSort" << std::endl;
    // basic_test(insertionSort<int>);
    // std::cout << "mergeSort" << std::endl;
    // basic_test(mergeSort<int>);
    // std::cout << "heapSort" << std::endl;
    // basic_test(heapSort<int>);
    // std::cout.flush();
  }
  auto test = [](const int N) {
    // SortTest T1(bubbleSort<int>);
    // T1.runtest(N);
    // SortTest T2(heapSort<int>);
    // T2.runtest(N);
    // SortTest T3(mergeSort<int>);
    // T3.runtest(N);
  };
  if (1) {
    test(10000);
  }
}