#include <bits/stdc++.h>
using namespace std;

int const N = 100;
int ones[N], ones_n = 0;
int twos[N], twos_n = 0;

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  int n; cin >> n;
  for (auto i = 0; i < n; i++)
  {
    int t; cin >> t;
    if (t == 1) cin >> ones[ones_n++];
    else cin >> twos[twos_n++];
  }

  sort(ones, ones + ones_n);
  sort(twos, twos + twos_n);

  auto best = ones_n + twos_n*2;
  for (auto i = 0; i <= ones_n; i++)
  {
    for (auto j = 0; j <= twos_n; j++)
    {
      auto w = 0;
      for (auto k = 0; k < i; k++)
        w += ones[k];
      for (auto k = 0; k < j; k++)
        w += twos[k];

      auto const t = (ones_n - i) + (twos_n - j)*2;
      if (w <= t && t < best)
        best = t;
    }
  }

  cout << best << endl;
}
