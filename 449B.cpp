//
// http://codeforces.com/problemset/problem/449/B
//
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edge;

int n, m, k, v[100001];
long long sp[100001];
vector<pair<int, int> > al[100001];

void shortest_path()
{
  v[1] = 1;
  for (int i = 2; i <= n; i++)
    v[i] = 0;

  priority_queue<edge, vector<edge>, greater<edge> > e;
  for (auto xv: al[1])
    e.push(make_tuple(xv.first, 1, xv.second));

  for (int cnt = 1; cnt != n; cnt++)
  {
    auto const xvu = e.top(); e.pop();
    v[get<2>(xvu)] = 1;
    sp[get<2>(xvu)] = sp[get<1>(xvu)] + get<0>(xvu);
    for (auto xu: al[get<2>(xvu)])
      if (v[xu.second] == 0)
        e.push(make_tuple(xu.first, get<2>(xvu), xu.second));
  }
}

int main()
{
  ios::sync_with_stdio(false);
  //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
  {
    int u, v, x; cin >> u >> v >> x;
    al[u].push_back(make_pair(x, v));
    al[v].push_back(make_pair(x, u));
  }

  shortest_path();

  int ret = 0;
  for (int i = 0; i < k; i++)
  {
    int s, y; cin >> s >> y;
    if (y >= sp[s]) ret++;
  }

  cout << ret << endl;
}
