#include <bits/stdc++.h>
using namespace std;

int const N = 501;
int n, k, c[N];
bool d[2][N][N] = {};

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n >> k;
  for (auto i = 1; i <= n; i++)
    cin >> c[i];

  d[0][0][0] = true;
  for (auto i = 1; i <= n; i++)
  {
    auto const curr = i%2;
    auto const prev = 1 - curr;
    for (auto j = 0; j <= k; j++)
      for (auto m = 0; m <= j; m++)
      {
        d[curr][j][m] = d[prev][j][m];
        if (c[i] <= j)
        {
          d[curr][j][m] |= d[prev][j-c[i]][m];
          if (c[i] <= m)
            d[curr][j][m] |= d[prev][j-c[i]][m-c[i]];
        }
      }
  }

  vector<int> v;
  for (auto i = 0; i <= k; i++)
    if (d[n%2][k][i])
      v.push_back(i);

  cout << v.size() << "\n";
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
