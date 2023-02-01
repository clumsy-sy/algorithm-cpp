#define PROBLEM "https://www.luogu.com.cn/problem/P4238"

#include "../../src/other/fastio.hpp"
#include "../../src/math/poly/poly-base.hpp"
#include "../../src/other/modint/montgomery-space.hpp"
#include "../../src/other/modint/static-modint.hpp"

using Space = MontgomerySpace<u32, 998244353>;
using ModT = StaticModint<Space>;
using FPS = Poly<ModT>;

i32 main() {
  FastI fin(stdin);
  FastO fout(stdout);
  u32 n;
  fin >> n;
  FPS f(n);

  for (auto &i : f)
    fin >> i;
  for (auto i : f.inv(n))
    fout << i << ' ';
  std::cerr << std::endl << detail::ntt_size << std::endl;
  return 0;
}
