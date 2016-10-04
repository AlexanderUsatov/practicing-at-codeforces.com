#include <bits/stdc++.h>
using namespace std;

int const aN = 100;
int n, a[aN], d[aN];

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n;

    for (int i = 1, k = 1; i < aN; k*=10) {
        a[i++] = k;
        for (int j = 1, u = i - 1; j < u; j++)
            a[i++] = k + a[j];
    }

    int ret = 0;
    for (; n > 0;) {
        auto it = lower_bound(a, a + aN, n);
        if (*it == n) {
            d[ret++] = *it;
            break;
        }
        else {
            n -= *(--it);
            d[ret++] = *it;
        }
    }

    cout << ret << endl;
    for (int i = 0; i < ret; i++)
        cout << d[i] << ' ';
    cout << endl;
}
