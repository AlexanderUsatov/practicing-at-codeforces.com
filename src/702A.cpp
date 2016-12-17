#include <bits/stdc++.h>
using namespace std;

int n, a[100000];

int main() {
    //ifstream input("input.txt");
    //cin.rdbuf(input.rdbuf());

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        for (; j < n && a[j - 1] < a[j]; j++);
        m = max(m, j - i);
        i = j;
    }

    cout << m << endl;
}
