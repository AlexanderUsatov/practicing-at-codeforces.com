//
// http://codeforces.com/problemset/problem/287/B
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  ll n, k;
  cin >> n >> k;
  n--;

  auto ret = 0LL;
  for (; n != 0 && k > 1;)
  {
    if (n < k)
    {
      ret++;
      n = 0;
      break;
    }

    ll i = k/2, j = k;
    auto s = 1LL * (i + j - 1)*(j - i)/2;
    for (; s > n;)
    {
      i = i + (j - i)/2;
      s = 1LL * (i + j - 1)*(j - i)/2;
    }

    n -= s;
    ret += k - i;
    k = i;
  }

  if (n == 0)
  {
    cout << ret << endl;
  }
  else
  {
    cout << "-1" << endl;
  }
}
