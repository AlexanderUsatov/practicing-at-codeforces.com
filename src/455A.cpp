#include <bits/stdc++.h>
using namespace std;

int const N = 100000;
int n, cnt[N + 1] = {}, m = 0;
long long d[N + 1] = {};

int main()
{
  //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  for (auto i = 0; i < n; i++)
  {
    int t; cin >> t;
    if (t > m) m = t;
    cnt[t]++;
  }

  d[1] = cnt[1];
  for (auto i = 2; i <= m; i++)
  {
    d[i] = max(d[i - 1], d[i - 2] + 1LL*cnt[i]*i);
  }

  cout << d[m] << endl;
}
