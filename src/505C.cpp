#include <bits/stdc++.h>
using namespace std;

int const N = 30001;
int n, d, m = 0;
int t[N] = {};
int dp[N][250 * 2];
bool solved[N][250 * 2] = {};

int solve(int i, int j)
{
    if (i > m)
        return 0;
    auto const jj = j - (d - 250);
    if (solved[i][jj])
        return dp[i][jj];
    solved[i][jj] = true;
    if (j == 1)
        dp[i][jj] = t[i] + max(solve(i + j, j), solve(i + j + 1, j + 1));
    else
        dp[i][jj] = t[i] + max(max(solve(i + j - 1, j - 1), solve(i + j, j)), solve(i + j + 1, j + 1));
    return dp[i][jj];
}

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    int j; cin >> j;
    t[j]++;
    m = max(m, j);
  }

  cout << solve(d, d) << endl;
}
