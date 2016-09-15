#include <bits/stdc++.h>
using namespace std;

int const N = 100001;
int n, a[N] = {}, m = 0, d[N][3] = {};

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  for (auto i = 0; i < n; i++)
  {
    int k; cin >> k;
    a[k - 1]++;
    m = max(m, k);
  }

  for (auto j = 0; j < m; j++)
  {
    for (auto i = 0; i < m; i++)
    {
      auto const k = j % 3;
      auto const k_1 = (k + 2) % 3;
      auto const k_2 = (k + 1) % 3;
      d[i][k] = max(
        d[i][k_1],
        d[i][k_2] + (j + 1)*a[j]);
    }
  }

  cout << d[m - 1][(m - 1) % 3] << endl;
}
