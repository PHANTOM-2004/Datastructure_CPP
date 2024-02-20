#include "Bitmap.hpp"

namespace CYT_DSA {
void Bitmap::init(const int n) { M = new char[N = (n + 7) / 8]{0}; }

Bitmap::Bitmap(const int n) { init(n); }

Bitmap::Bitmap(const char* const filename, const int n) {
  init(n);
  std::ifstream fin(filename, std::ios_base::in | std::ios_base::binary);
  if (fin.is_open() == false) {
    std::cerr << "input error : 输入文件文件[" << filename << "]打开失败\n";
    return;
  }
  fin.read(M, N);
  fin.close();
}

bool Bitmap::test(const int k) {
  expand(k);
  return M[k >> 3] & MASK(k);
}

void Bitmap::set(const int k) {
  expand(k);
  if (test(k) == false) {
    valid_size++;
    M[k >> 3] |= MASK(k);
  }
}

void Bitmap::clear(const int k) {
  expand(k);
  if (test(k) == true) {
    valid_size--;
    M[k >> 3] &= ~MASK(k);
  }
}

void Bitmap::expand(const int k) {
  if (k < 8 * N) return;
  char* old_mem = M;
  int old_n = N;
  init(2 * k);
  memcpy(M, old_mem, old_n);
  delete[] old_mem;
}

void Bitmap::dump(const char* const filename) const {
  std::ofstream fout(filename, std::ios_base::out | std::ios_base::binary);
  if (fout.is_open() == false) {
    std::cerr << "output error : 输出文件文件[" << filename << "]打开失败\n";
    return;
  }
  fout.write(M, N);

  fout.close();
}

std::string Bitmap::to_string(const int n) {
  std::string res;
  res.reserve(n);
  for (int i = 0; i < n; i++) {
    res.push_back(test(i) ? '1' : '0');
  }
  return res;
}
}  // namespace CYT_DSA