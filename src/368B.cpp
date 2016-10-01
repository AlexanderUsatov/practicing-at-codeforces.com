#include <bits/stdc++.h>
using namespace std;

int const N = 100002;
int n, m, a[N], cnt[N] = {}, d[N] = {};

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i > 0; i--) {
        d[i] = d[i + 1];
        if (cnt[a[i]]++ == 0)
            d[i]++;
    }

    for (int i = 0; i < m; i++) {
        int l; cin >> l;
        cout << d[l] << '\n';
    }
}
