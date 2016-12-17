#include <bits/stdc++.h>
using namespace std;

string a, b;

float solve(int const i, int const ax, int const bx, float p)
{
    if (i == a.length())
        return ax == bx ? p : 0;

    int const d = a[i] == '-' ? -1 : 1;
    int const aa = ax + d;
    if (a[i] == b[i]) {
        return solve(i + 1, aa, bx + d, p);
    }
    else if (b[i] == '-') {
        return solve(i + 1, aa, bx - 1, p);
    }
    else if (b[i] == '+') {
        return solve(i + 1, aa, bx + 1, p);
    }
    else
    {
        assert(b[i] == '?');
        return solve(i + 1, aa, bx + 1, 0.5 * p) +
               solve(i + 1, aa, bx - 1, 0.5 * p);
    }
}

int main() {
    //ifstream input("input.txt");
    //cin.rdbuf(input.rdbuf());

    getline(cin, a);
    getline(cin, b);
    cout << fixed << setprecision(9) << solve(0, 0, 0, 1) << endl;
}
