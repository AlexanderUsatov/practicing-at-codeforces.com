#include <bits/stdc++.h>
using namespace std;

string s;
int d[100001], n;

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    getline(cin, s);

    d[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        d[i] = d[i - 1];
        if (s[i - 1] == s[i])
            d[i]++;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        cout << d[r - 1] - d[l - 1] << '\n';
    }
}
