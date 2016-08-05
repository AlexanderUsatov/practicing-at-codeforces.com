//
// http://codeforces.com/problemset/problem/455/C
//
#include <bits/stdc++.h>

using namespace std;

int const NMax = 300001;

int n, m, q;
int uf[NMax]; // union find
int r[NMax]; // rank
list<int> al[NMax]; // adjacency list
int dst[NMax]; // distance (bfs)
int dia[NMax]; // diameter
set<int> visited;

int find(int a)
{
  int b = a;
  for (; uf[b] != b; b = uf[b]);
  uf[a] = b;
  return b;
}

void join(int a, int b)
{
  a = find(a);
  b = find(b);
  if (a == b)
  {
    return;
  }

  int const d = max(dia[a], max(dia[b], (dia[a] + 1) / 2 + (dia[b] + 1) / 2 + 1));
  if (r[b] < r[a])
  {
    uf[b] = a;
    dia[a] = d;
  }
  else if (r[a] < r[b])
  {
    uf[a] = b;
    dia[b] = d;
  }
  else
  {
    uf[a] = b;
    dia[b] = d;
    r[b] = r[a] + 1;
  }
}

int bfs(int a)
// returns index of maximum dst[index] found
{
  if (uf[a] == 0)
  {
    uf[a] = a;
    r[a] = 1;
  }

  int i = a;
  queue<int> q;
  for (auto v : visited) dst[v] = 0;
  for (visited.clear(), visited.insert(a), q.push(a); !q.empty();)
  {
    int v = q.front(); q.pop();
    for (auto w : al[v])
    {
      if (visited.insert(w).second)
      {
        dst[w] = dst[v] + 1;
        i = w;
        q.push(w);
        if (uf[w] == 0) uf[w] = a;
      }
    }
  }

  return i;
}

int diameter(int a)
{
  auto const i = bfs(a);
  auto const v = dst[i];
  return max(v, dst[bfs(i)]);
}

int main()
{
  cin >> n >> m >> q;

  for (int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    al[a].push_back(b);
    al[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    if (uf[i] == 0)
    {
      dia[i] = diameter(i);
    }
  }

  for (int i = 0; i < q; i++)
  {
    int e, a; cin >> e >> a;
    switch (e)
    {
    case 1:
      cout << dia[find(a)] << endl;
      break;
    case 2:
      int b; cin >> b;
      join(a, b);
      break;
    }
  }
}
