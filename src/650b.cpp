#include <bits/stdc++.h>
using namespace std;

int N, a, b, T;
bool w[500001] = {};
bool v[500001] = {};

int solve(int i, int n, int t)
{
  if (n >= N || t <= 0)
  {
    return n;
  }

  auto const vi = v[i];
  if (!vi)
  {
    t--;
    if (w[i]) t -= b;
    v[i] = true;
    n++;
  }

  int ret = max(
    solve(i == 1 ? N : i - 1, n, t - a),
    solve(i == N ? 1 : i + 1, n, t - a));
  if (!vi)
  {
    n--;
    v[i] = false;
    if (w[i]) t += b;
    t++;
  }

  return ret;
}

int main()
{
  ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  cin >> N >> a >> b >> T;
  for (int i = 1; i <= N; i++)
  {
    char ch; cin >> ch;
    if (ch == 'w') w[i] = true;
  }

  cout << solve(1, 0, T) << endl;
}
