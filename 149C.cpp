//
// Разделение на команды
// http://codeforces.com/problemset/problem/149/C
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++)
    {
        int p; cin >> p;
        a.push_back(make_pair(p, i));
    }

    sort(a.begin(), a.end());

    vector<int> t1, t2;
    for (int i = a.size() - 1; i >= 0;)
    {
        t1.push_back(a[i--].second);
        if (i >= 0) t2.push_back(a[i--].second);
    }

    cout << t1.size() << endl;
    for (auto i: t1) cout << i << ' ';
    cout << endl << t2.size() << endl;
    for (auto i: t2) cout << i << ' ';
    cout << endl;
}
