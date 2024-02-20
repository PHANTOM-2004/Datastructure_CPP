#pragma once

#include <cstring>
#include <fstream>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

namespace CYT_DSA {

class Bitmap {
 public:
  Bitmap(const int n = BITMAP_DEFAULT_SIZE);
  Bitmap(const char* const filename, const int n = BITMAP_DEFAULT_SIZE);
  ~Bitmap() { delete[] M; };

  void set(const int k);
  void clear(const int k);
  bool test(const int k);

  bool operator[](const int k) { return test(k); }
  constexpr int truebit() const { return valid_size; }
  constexpr int length() const { return N; }
  constexpr int size() const { return N * 8; }

  void dump(const char* const filename) const;  // 导出至指定文件
  std::string to_string(const int n);     // 前n位转换为字符串

 protected:
  char* M;
  int N;
  mutable int valid_size = 0;  // size个有效位, size个1的存在

  void init(const int n);
  void expand(const int k);
  constexpr unsigned MASK(const unsigned k) const { return 0x80 >> (k & 0x07); }
  static const int BITMAP_DEFAULT_SIZE = 8  ;
};

}  // namespace CYT_DSA

