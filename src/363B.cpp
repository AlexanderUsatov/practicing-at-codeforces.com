#include <bits/stdc++.h>
using namespace std;

int n, a[150000], k;

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n >> k;
    for (auto i = 0; i < n; i++)
        cin >> a[i];

    auto j = 0, s = 0;
    for (; j < k; j++)
        s += a[j];

    auto ret = 1;
    for (auto i = 0, ss = s; j < n; i++, j++) {
        ss = ss - a[i] + a[j];
        if (ss < s) {
            s = ss;
            ret = i + 2;
        }
    }

    cout << ret << endl;
}
