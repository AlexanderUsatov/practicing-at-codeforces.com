#include <bits/stdc++.h>
using namespace std;

int const N = 5 * 100000 + 1;
int n, a[N], cnt[N] = {};

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n;
    auto s3 = 0LL;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s3 += a[i];
    }

    if (s3 % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    s3 /= 3;
    auto s = 0LL;
    for (int i = 1; i < n - 1; i++) {
        cnt[i] = cnt[i - 1];
        s += a[i];
        if (s == s3)
            cnt[i]++;
    }

    s = 0LL;
    auto ret = 0LL;
    for (int i = n; i > 2; i--) {
        s += a[i];
        if (s == s3)
            ret += cnt[i - 2];
    }

    cout << ret << endl;
}
