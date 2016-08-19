//
// Выравнивание по центру
// http://codeforces.com/problemset/problem/5/B
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> lines;
    size_t width = 0;
    for (string s; getline(cin, s); lines.push_back(s))
    {
        if (width < s.length())
        {
            width = s.length();
        }
    }

    bool pad_r = false; // aline left first
    for (size_t i = 0; i < width + 2; i++) cout << '*';
    for (auto line: lines)
    {
        size_t const w = (width - line.length());

        cout << endl << '*';
        for (size_t i = 0; i < w / 2; i++) cout << ' ';
        if (w % 2 != 0 && pad_r) cout << ' ';
        cout << line;
        for (size_t i = 0; i < w / 2; i++) cout << ' ';
        if (w % 2 != 0 && !pad_r) cout << ' ';
        cout << '*';

        if (w % 2 != 0) pad_r = !pad_r;
    }
    cout << endl;
    for (size_t i = 0; i < width + 2; i++) cout << '*';
    cout << endl;
}
