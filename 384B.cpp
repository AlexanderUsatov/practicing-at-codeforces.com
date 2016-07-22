//
// http://codeforces.com/contest/384/problem/B
//
#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << (m * (m - 1)) / 2 << endl;
    if (k == 0)
    {
        for (int i = 1; i < m; i++)
            for (int j = i + 1; j <= m; j++)
                cout << i << ' ' << j << endl;
    }
    else
    {
        for (int i = m; i > 1; i--)
            for (int j = i - 1; j > 0; j--)
                cout << i << ' ' << j << endl;
    }
}
