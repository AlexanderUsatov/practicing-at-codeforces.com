//
// http://codeforces.com/problemset/problem/582/B
//
#include <bits/stdc++.h>
using namespace std;

int n, T, a[100];
typedef long long M[100][100];

void mul(M const &a, M const &b, M &res)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = numeric_limits<int>::min();
      for (int k = 0; k < n; k++) {
        res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
}

void copy(M const &a, M &b)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i][j] = a[i][j];
    }
  }
}

void one(M &a)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
}

M tmp, aa;
void pow(M const &a, int n, M &out)
{
  for (one(out), copy(a, aa); n;)
  {
    if (n & 1) {
      mul(out, aa, tmp);
      copy(tmp, out);
    }

    mul(aa, aa, tmp);
    copy(tmp, aa);
    n >>= 1;
  }
}

M d, dd;
int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n >> T;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] > a[j]) {
        d[i][j] = numeric_limits<int>::min();
      }
      else {
        d[i][j] = 1;
        for (int k = 0; k < j; k++) {
          if (a[k] <= a[j]) {
            d[i][j] = max(d[i][j], d[i][k] + 1);
          }
        }
      }
    }
  }

  pow(d, T, dd);

  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res = max(res, dd[i][j]);
    }
  }

  cout << res << endl;
}
