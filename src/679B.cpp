//
// http://codeforces.com/contest/679/problem/B
//

#include <iostream>
#include <utility>

using namespace std;

typedef unsigned long long Ull;
typedef pair<Ull, Ull> NX;

NX theBest;

void FindTheBest(Ull m, NX const &xn)
{
    if (m == 0) {
        theBest = max(theBest, xn);
    }
    else {
        Ull x = 1;
        Ull x3 = 1;
        for (Ull xPlusOne3 = (x + 1)*(x + 1)*(x + 1);
             xPlusOne3 <= m;
             x3 = xPlusOne3, x += 1, xPlusOne3 = (x + 1)*(x + 1)*(x + 1));
        FindTheBest(m - x3, NX(xn.first + 1, xn.second + x3));

        if (x - 1 > 0) {
            Ull xMinusOne3 = (x-1)*(x-1)*(x-1);
            FindTheBest(x3 - 1 - xMinusOne3, NX(xn.first + 1, xn.second + xMinusOne3));
        }
    }
}

int main()
{
    Ull m;
    cin >> m;
    FindTheBest(m, NX(0, 0));
    cout << theBest.first << ' ' << theBest.second << endl;
}
