//
// Остров невезения
// http://codeforces.com/contest/540/problem/D
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int R, S, P;
    cin >> R >> S >> P;
    vector<vector<vector<long double>>> d(
        R + 1, vector<vector<long double>>(
        S + 1, vector<long double>(
        P + 1))); 
    d[R][S][P] = 1;
    for (int r = R; r >= 0; r--) {
        for (int s = S; s >= 0; s--) {
            for (int p = P; p >= 0; p--)
            {
                auto const rp = r * p;
                auto const rs = r * s;
                auto const sp = s * p;
                auto const total = rp + rs + sp;
                if (total == 0) continue;
                if (r > 0) d[r - 1][s][p] += d[r][s][p] * rp / total;
                if (s > 0) d[r][s - 1][p] += d[r][s][p] * rs / total;
                if (p > 0) d[r][s][p - 1] += d[r][s][p] * sp / total;
            }
        }
    }

    long double p1 = 0, p2 = 0, p3 = 0;
    for (int i = 1; i <= R; i++) p1 += d[i][0][0];
    for (int i = 1; i <= S; i++) p2 += d[0][i][0];
    for (int i = 1; i <= P; i++) p3 += d[0][0][i];

    cout << setprecision(12);
    cout << p1 << ' ' << p2 << ' ' << p3 << endl;
}
