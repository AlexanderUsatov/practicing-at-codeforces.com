#include <bits/stdc++.h>
using namespace std;

int const N = 100000;
int n, a[N];

int main()
{
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  for (auto i = 0; i < n; i++)
    cin >> a[i];

  auto i = 0, j = 0, ret = 1;
  for (; j < n; i = ++j)
  {
    for (; j < n - 1 && a[j] <= a[j + 1]; j++);
    ret = max(ret, j - i + 1);
  }

  cout << ret << endl;
}
