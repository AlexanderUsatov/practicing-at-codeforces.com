// See also:
// http://codeforces.com/blog/entry/18329?#comment-242724
// http://codeforces.com/contest/550/submission/12143232

#include <bits/stdc++.h>
using namespace std;

void printYES(int n) {
    cout << "YES" << endl;
    cout << n << endl;
}

int main() {
    //ifstream input("input.txt");
    //cin.rdbuf(input.rdbuf());

    string s;
    getline(cin, s);
    int const n = s.length();

    for (int i = 0; i < n; i++) {
        int const si = s[i] - '0';
        if (si % 8 == 0) {
            printYES(si);
            return 0;
        }

        for (int j = i + 1; j < n; j++) {
            int const sj = s[j] - '0';
            int const sij = si * 10 + sj;
            if (sij % 8 == 0) {
                printYES(sij);
                return 0;
            }

            for (int k = j + 1; k < n; k++) {
                int const sk = s[k] - '0';
                int const sijk = sij * 10 + sk;
                if (sijk % 8 == 0) {
                    printYES(sijk);
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;
}
