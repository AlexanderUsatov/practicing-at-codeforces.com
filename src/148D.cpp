#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, double> m;

double solve(int w, int b)
{
    if (w <= 0) return 0;
    if (b <= 0) return 1;

    auto const wb = std::make_pair(w, b);
    auto const it = m.find(wb);
    if (it != m.end()) return it->second;

    //! princess wins
    auto const p = 1. * w / (w + b);

    //! princess chose black
    auto cont_p = 1. * b / (w + b);
    b--;

    //! gragon chose black
    cont_p *= 1. * b / (w + b);
    b--;

    auto ret = p;
    if (cont_p > 1e-13)
    {
        //! white mouse jumped out
        auto const p_white = solve(w - 1, b) * (1.* w / (w + b));
        //! black mouse jumped out
        auto const p_black = solve(w, b - 1) * (1.* b / (w + b));
        ret += cont_p * (p_white + p_black);
    }

    m[wb] = ret;
    return ret;
}

int main()
{
    //ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

    int w, b;
    cin >> w >> b;
    cout << fixed << setprecision(9) << solve(w, b) << endl;
}
