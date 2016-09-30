#include <bits/stdc++.h>
using namespace std;

int a1, a2, d[151][151] = {};

int solve(int a1, int a2)
{
  if (a1 <= 0 || a2 <= 0)
    return 0;

  if (a1 < 2 && a2 < 2)
    return 0;

  if (d[a1][a2] != 0)
    return d[a1][a2];

  d[a1][a2] = 1 + max(solve(a1 - 2, a2 + 1), solve(a1 + 1, a2 - 2));
  return d[a1][a2];
}

int main()
{
  //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> a1 >> a2;
  cout << solve(a1, a2) << endl;
}
