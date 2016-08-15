#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef tuple<ld, int, int> t;

int n;
ld a[4000];
int u[4000];

int main()
{
  ios::sync_with_stdio(false);
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  cin >> n;
  for (int i = 0; i < 2 * n; i++) cin >> a[i];

  priority_queue<t, vector<t>, greater<t>> min_heap;
  for (int i = 0; i < 2 * n; i++) {
      for (int j = i + 1; j < 2 * n; j++) {
          auto const sum = a[i] + a[j];
          min_heap.push(make_tuple(
              min(abs(sum - (floor(a[i]) + ceil(a[j]))),
                  abs(sum - (floor(a[j]) + ceil(a[i])))),
              i, j));
          u[i] = 0; u[j] = 0;
      }
  }

  ld res = 0;
  for (int i = 0; i < n; ) {
      auto const d = get<0>(min_heap.top());
      auto const j = get<1>(min_heap.top());
      auto const k = get<2>(min_heap.top());
      if (u[j] == 0 && u[k] == 0)
      {
          u[j] = 1; u[k] = 1;
          res += d;
          i++;
      }

      min_heap.pop();
  }

  cout << fixed << setprecision(3) << res;
}
