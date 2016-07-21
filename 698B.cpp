//
// http://codeforces.com/contest/698/problem/B
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> tree, is_visited, roots;

void visit_up(int v)
{
    set<int> s;
    for (; is_visited[v] == 0; v = tree[v])
    {
        is_visited[v] = 1;
        s.insert(v);
    }

    if (s.find(v) != s.cend())
    {
        roots.push_back(v);
    }
}

int main()
{
    cin >> n;
    tree.resize(n + 1, 0);
    is_visited.resize(n + 1, 0);
    for (auto i = 1; i <= n; i++)
    {
        cin >> tree[i];
        if (i == tree[i]) roots.push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (is_visited[i] == 0) visit_up(i);
    }

    int ans = 0;
    auto const root = roots.cbegin();
    if (tree[*root] != *root)
    {
        tree[*root] = *root;
        ans++;
    }

    for (auto it = next(root); it != roots.end(); ++it)
    {
        if (tree[*it] != *root)
        {
            tree[*it] = *root;
            ans++;
        }
    }

    cout << ans << endl;
    for (int i = 1; i < n; i++)
    {
        cout << tree[i] << ' ';
    }

    cout << tree[n] << endl;
}
