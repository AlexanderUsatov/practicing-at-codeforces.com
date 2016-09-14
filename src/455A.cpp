#include <bits/stdc++.h>
using namespace std;

int const N = 100000;
int n, a[N], d[N][3] = {};

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  for (auto i = 0; i < n; i++)
    cin >> a[i];

  for (auto j = 0; j < n; j++)
  {
    for (auto i = 0; i < n; i++)
    {
      auto const k = j%3;
      auto const k_1 = (k + 2)%3;
      auto const k_2 = (k + 1)%3;
      d[i][k] = max(
        d[i][k_1],
        d[i][k_2] + a[j]);
    }
  }

  cout << d[n - 1][(n - 1)%3] << endl;
}
