#include <bits/stdc++.h>
using namespace std;

int f[50];

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  int n, m; cin >> n >> m;
  for (auto i = 0; i < m; i++)
    cin >> f[i];

  sort(f, f + m);
  auto ret = f[n - 1] - f[0];
  for (auto i = 1; i <= m - n; i++)
  {
    ret = min(ret, f[n - 1 + i] - f[i]);
  }

  cout << ret << endl;
}
