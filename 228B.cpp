//
// http://codeforces.com/problemset/problem/228/B
//
#include <iostream>
#include <vector>

using namespace std;
int n, m,
    n2, m2;

int main()
{
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
        }
    }

    cin >> n2 >> m2;
    vector<vector<int> > b(n2, vector<int>(m2));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            char ch; cin >> ch;
            b[i][j] = ch - '0';
        }
    }

    pair<int, int> xy;
    int value = 0;
    for (int x = 0 - max(n, n2); x < max(n, n2); x++) {
        for (int y = 0 - max(m, m2); y < max(m, m2); y++)
        {
            int acc = 0;
            for (int i = max(0, 0 - x); i < n && i + x < n2; i++) {
                for (int j = max(0, 0 - y); j < m && j + y < m2; j++) {
                    acc += a[i][j] * b[i + x][j + y];
                }
            }

            if (value < acc)
            {
                xy = make_pair(x, y);
                value = acc;
            }
        }
    }

    cout << xy.first << ' ' << xy.second << endl;
}
