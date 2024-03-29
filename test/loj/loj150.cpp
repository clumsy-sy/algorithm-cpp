#define PROBLEM "https://loj.ac/p/143"

#define ALGO_IO_NUMBER_ONLY

// #define ALGO_DISABLE_SIMD_AVX2
// #define ALGO_DISABLE_NTT_RADIX_4
// #define ALGO_DISABLE_NTT_CLASSICAL
// #define ALGO_DYNAMIC_MOD

#include "../../src/other/fastio.hpp"
#include "../../src/math/poly/poly-base.hpp"

#ifndef ALGO_DYNAMIC_MOD
#include "../../src/other/modint/montgomery-space.hpp"
#include "../../src/other/modint/static-modint.hpp"
using Space = MontgomerySpace<u32, 998244353>;
using ModT = StaticModint<Space>;
#else
#include "../../src/other/modint/dynamic-montgomery-space.hpp"
#include "../../src/other/modint/dynamic-modint.hpp"
using Space = DynamicMontgomerySpace<u32, 1>;
using ModT = DynamicModint<Space>;
#endif

using FPS = Poly<ModT>;

i32 main() {
  FastI fin(stdin);
  FastO fout(stdout);
#ifdef ALGO_DYNAMIC_MOD
  ModT::set_mod(998244353);
#endif
  u32 n, k;
  fin >> n >> k;
  n++;
  FPS f(n);
  for (auto &i : f)
    fin >> i;
  auto ans = ((f - FPS{f[0] - 2} - f.invsqrt(n).integr(n).exp(n)).ln(n) + FPS{ModT(1)}).pow(k, n).deriv(n - 1);
  for (const auto &i : ans)
    fout << i << ' ';
  return 0;
}
