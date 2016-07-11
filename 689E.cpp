//
// http://codeforces.com/problemset/problem/689/E
//
#include <map>
#include <iostream>
#include <string>

using namespace std;
int const mod = 1000000007;
const int nmax = 2e5 + 5;

int f[nmax]; // factorial(i)
int c[nmax]; // 1 / factorial(i)

int chooseMod(int n, int k)
{
    int ans = (1ll * f[n] * c[k]) % mod;
    return (1ll * ans * c[n - k]) % mod;
}

int powMod(int a,int b)
{
    int ans = 1;
    while (b)
    {
        if (b&1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b /= 2;
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string empty;
    getline(cin, empty);

    map<int,int> events;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        getline(cin, empty);
        ++events[l];
        --events[r + 1];
    }

    f[0] = c[0] = 1;
    for (int i = 1;i <= n;++i)
    {
        f[i] = (1ll * f[i-1] * i) % mod;
        c[i] = powMod(f[i], mod-2);
    }

    int balance = 0,
       prev = events.begin()->first,
       sum = 0;
    for (auto it: events)
    {
        if (balance >= k) {
            sum += (1LL * (it.first - prev) * chooseMod(balance, k)) % mod;
            sum %= mod;
        }

        balance += it.second;
        prev = it.first;
    }

    cout << sum << endl;
}
