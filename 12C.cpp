//
// Выравнивание по центру
// http://codeforces.com/problemset/problem/5/B
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n); // price vector
    for (int i = 0; i < n; i++) cin >> p[i];
    map<string, int> cm; // fruite count map
    for (int i = 0; i < m; i++)
    {
        string f; cin >> f;
        cm[f]++;
    }

    vector<int> cv; cv.reserve(cm.size()); // fruite count vector
    for (auto p: cm) cv.push_back(p.second);

    sort(p.begin(), p.end());
    sort(cv.begin(), cv.end());

    pair<int, int> mm; // min / max
    for (size_t i = 0; i < cv.size(); i++) mm.first += p[i]*cv[cv.size() - 1 - i];
    for (size_t i = 0; i < cv.size(); i++) mm.second += p[p.size() - 1 - i]*cv[cv.size() - 1 - i];

    cout << mm.first << ' ' << mm.second << endl;
}
