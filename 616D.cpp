//
// http://codeforces.com/problemset/problem/616/D
//
#include <bits/stdc++.h>
using namespace std;

int n, k, a[500001], cnt[1000001];

int main()
{
  ios::sync_with_stdio(false);
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]] = 0;
  }

  int l = 1, r = 1;
  cnt[a[r]] = 1;
  for (int i = l, j = r, t = 1; j < n;)
  {
    for (; t <= k && j <= n;)
    {
      if (++cnt[a[++j]] == 1)
      {
        ++t;
      }
    }

    if (r - l < j - i - 1)
    {
      l = i;
      r = j - 1;
    }

    for (; t > k && i <= n;)
    {
      if (--cnt[a[i++]] == 0)
      {
        --t;
      }
    }
  }

  cout << l << ' ' << r << endl;
}
