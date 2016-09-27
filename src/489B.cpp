#include <bits/stdc++.h>
using namespace std;

int const N = 100;
int n, mans[N], m, girls[N];

int main()
{
  //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> mans[i];

  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> girls[i];

  sort(mans, mans + n);
  sort(girls, girls + m);

  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (abs(mans[i] - girls[j]) <= 1) {
        ret++;
        girls[j] = numeric_limits<int>::max();
        break;
      }
    }
  }

  cout << ret << endl;
}
