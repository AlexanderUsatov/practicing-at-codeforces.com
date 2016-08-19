//
// Протест Джерри
// http://codeforces.com/problemset/problem/626/D
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(&a[0], &a[n]);
    map<int, int> cnt;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[a[j] - a[i]]++;
        }
    }

    const auto dmax = a[n-1] - a[0];
    vector<long long> cnt2(dmax + 1);
    for (int i = 1; i <= dmax; i++) {
        for (int j = 1; i + j <= dmax; j++) {
            cnt2[i + j] += 1ll * cnt[i] * cnt[j];
        }
    }

    long double ans = 0;
    const auto n2 = n * (n - 1) / 2;
    for (int i = 2; i < dmax; i++) {
        for (int j = i + 1; j <= dmax; j++) {
            ans += 1. * cnt2[i] * cnt[j] / n2 / n2 / n2;
        }
    }

    cout << setprecision(9);
    cout << ans << endl;
}
