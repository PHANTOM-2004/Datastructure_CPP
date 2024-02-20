#pragma once

#include <iostream>

void msg(const char *msg_, const bool begin = true) {
  std::cout << "_______________________";
  std::cout << msg_ << " test " << (begin ? "begin" : "end");
  std::cout << "_______________________\n" << std ::endl;
}

template <typename T>
void show(T &t) {
  std::cout << t << ' ';
}

inline int dice(const int range) { return rand() % range; }
