#pragma once
#include "Bitmap/Bitmap.hpp"

namespace Prime {
static constexpr int prime_limit = 1048576;
static const char* const prime_filename = "PrimeN_1048576.hex";

int primeNLT(int c, const int n = prime_limit,
             const char* const filename = prime_filename);
}  // namespace Prime
