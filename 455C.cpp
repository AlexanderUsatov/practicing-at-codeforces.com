//
// http://codeforces.com/problemset/problem/455/C
//
#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<int> uf; // union find
vector<vector<int>> al; // adjacency list
vector<int> dst; // distance (bfs)
vector<int> dia; // diameter

void join(int a, int b)
{
	if (a == b)
	{
		return;
	}

	int const ufa = uf[a], ufb = uf[b];
	for (int i = 1; i <= n; i++)
	{
		if (uf[i] == ufb)
		{
			uf[i] = ufa;
		}
	}
}

void bfs(int a)
{
	queue<int> q;
	vector<bool> visited(n + 1);

	visited[a] = true;
	if (uf[a] == 0) uf[a] = a;
	q.push(a);
	fill(dst.begin(), dst.end(), 0);

	for (; !q.empty();)
	{
		int v = q.front(); q.pop();
		for (auto w : al[v])
		{
			if (!visited[w])
			{
				visited[w] = true;
				if (uf[w] == 0)  uf[w] = a;
				q.push(w);
				dst[w] = dst[v] + 1;
			}
		}
	}
}

int diameter(int a)
{
	bfs(a);
	auto const d1 = max_element(dst.begin(), dst.end());
	auto const d1v = *d1;
	bfs(distance(dst.begin(), d1));
	return max(d1v, *max_element(dst.begin(), dst.end()));
}

int main()
{
	cin >> n >> m >> q;

	uf.resize(n + 1);
	al.resize(n + 1);
	dst.resize(n + 1);
	dia.resize(n + 1);

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
			cout << dia[uf[a]] << endl;
			break;
		case 2:
			int b; cin >> b;
			int const ufa = uf[a], ufb = uf[b];
			if (ufa != ufb)
			{
				dia[ufa] = max(dia[ufa], max(dia[ufb], (dia[ufa] + 1) / 2 + (dia[ufb] + 1) / 2 + 1));
			}
			join(a, b);
			break;
		}
	}
}
