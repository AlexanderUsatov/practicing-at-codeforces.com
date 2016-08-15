//
// http://codeforces.com/problemset/problem/351/A
//
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  int cnt = 0;
  double m = n;
  for (int i = 0; i < 2 * n; i++)
  {
    double a; cin >> a;
    a -= static_cast<int>(a);
    if (a == 0) cnt++;
    else m -= a;
  }

  double ret = numeric_limits<double>::max();
  for (int i = 0; i <= min(n, cnt); i++)
  {
    ret = min(ret, abs(m - i) * 1.);
  }

  cout << fixed << setprecision(3) << ret;
}
