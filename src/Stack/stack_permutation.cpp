#include <iostream>
#include <stack>
#include <vector>


void valid_sequence(const std::vector<int>&A, const std::vector<int>& B) {
  std::stack<int> S;
  auto itera = A.begin();
  for (const int& iter : B) {
    while (S.empty() || iter != S.top()) S.push(*itera++);
    S.pop();
  }
}
