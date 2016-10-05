#include <bits/stdc++.h>
using namespace std;

int n, a[10];

int main()
{
    //fstream input("input.txt"); cin.rdbuf(input.rdbuf());
    cin >> n;

    int ret = 0;
    for (; n != 0;) {
        int m = n, k = 0;
        for (int p = 1; m != 0;) {
            if (m % 10 != 0)
                k += p;
            p *= 10;
            m /= 10;
        }

        a[ret++] = k;
        n -= k;
    }

    cout << ret << '\n';
    copy(a, a + ret, ostream_iterator<int>(cout, " "));
}
