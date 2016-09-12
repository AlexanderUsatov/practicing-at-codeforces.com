#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int> > al; // adjacency list
vector<set<int> > ali; // adjacency list inversion

int solve(int v)
{
    auto ret = 0;
    queue<int> q;
    q.push(v);
    set<int> s;
    while (!q.empty())
    {
        v = q.front(); q.pop();
        s.insert(v);
        for (auto const w : al[v])
        {
            if (s.find(w) == s.end())
                q.push(w);
        }

        for (auto const w : ali[v])
        {
            if (s.find(w) == s.end())
            {
                q.push(w);
                ret++;
            }
        }
    }

    return ret;
}

int main()
{
    //ifstream input("input.txt");
    //cin.rdbuf(input.rdbuf());

    cin >> n;
    al.resize(n + 1);
    ali.resize(n + 1);
    for (auto i = 1; i < n; i++)
    {
        int s, t; cin >> s >> t;
        al[s].insert(t);
        ali[t].insert(s);
    }

    queue<pair<int, int> > q;
    q.push(make_pair(solve(1), 1));
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-1 * q.front().first, -1));
    set<int> s;
    while (!q.empty())
    {
        auto const c = q.front().first;
        auto const v = q.front().second;
        s.insert(v);
        q.pop();

        for (auto const w : al[v])
        {
            if (s.find(w) == s.end())
            {
                q.push(make_pair(c + 1, w));
                pq.push(make_pair(-1 * (c + 1), -1 * w));
            }
        }

        for (auto const w : ali[v])
        {
            if (s.find(w) == s.end())
            {
                q.push(make_pair(c - 1, w));
                pq.push(make_pair(-1 * (c - 1), -1 * w));
            }
        }
    }

    auto const best = pq.top();
    cout << -1 * best.first << endl;
    cout << -1 * best.second;
    pq.pop();
    while (!pq.empty() && pq.top().first == best.first)
    {
        cout << ' ' << -1 * pq.top().second;
        pq.pop();
    }
}
