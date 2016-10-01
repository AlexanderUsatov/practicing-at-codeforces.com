#include <bits/stdc++.h>
using namespace std;

int const N = 5*100000 + 1;
int a[N], n;
long long d[N];

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }

    int ret = 0;
    for (int i = n; i > 2; i--) {
        for (int j = 2; j < i; j++) {
            auto const sum1 = d[j - 1];
            auto const sum2 = d[i - 1] - d[j - 1];
            auto const sum3 = d[n] - d[i - 1];
            if (sum1 == sum2 && sum2 == sum3)
                ret++;
        }
    }

    cout << ret << endl;
}
