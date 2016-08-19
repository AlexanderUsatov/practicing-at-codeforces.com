//
// http://codeforces.com/contest/682/problem/D
//
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    size_t unused, cnt = 4;
    cin >> unused >> unused >> cnt;
    string empty, s, t;
    getline(cin, empty);
    getline(cin, s);
    getline(cin, t);

    vector<vector<vector<vector<size_t>>>> m(
        s.length() + 1, vector<vector<vector<size_t>>>(
        t.length() + 1, vector<vector<size_t>>(
        cnt + 1, vector<size_t>(
        2, 0))));
    for (size_t i = 0; i < s.length(); i++) {
        for (size_t j = 0; j < t.length(); j++) {
            for (size_t k = 0; k < cnt; k++) {
                for (size_t e = 0; e < 2; e++) {
                    m[i + 1][j][k][0] = max(m[i + 1][j][k][0], m[i][j][k][e]);
                    m[i][j + 1][k][0] = max(m[i][j + 1][k][0], m[i][j][k][e]);
                }

                if (s[i] == t[j]) {
                    m[i + 1][j + 1][k][1] = max(m[i + 1][j + 1][k][1], m[i][j][k][1] + 1);
                    m[i + 1][j + 1][k + 1][1] = max(m[i + 1][j + 1][k + 1][1], m[i][j][k][0] + 1);
                }
            }
        }
    }

    size_t valueMax = 0;
    for (size_t i = 1; i < s.length() + 1; i++) {
        for (size_t j = 1; j < t.length() + 1; j++) {
            for (size_t k = 0; k < cnt; k++) {
                for (size_t e = 0; e < 2; e++) {
                    if (valueMax < m[i][j][k][e]) {
                        valueMax = m[i][j][k][e];
                    }
                }
            }
        }
    }

    cout << valueMax << endl;
}
