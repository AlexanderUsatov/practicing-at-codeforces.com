//
// http://codeforces.com/problemset/problem/689/E
//
#include <map>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long Ull;
typedef long long Ll;

Ull
choose(Ull n, Ull k) {
    if (k > n) {
        return 0;
    }

    Ull r = 1;
    for (Ull d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }

    return r;
}

int main()
{
    size_t n, k;
    cin >> n >> k;
    string empty;
    getline(cin, empty);

    map<Ll, Ll> events;
    for (size_t i = 0; i < n; i++) {
        Ll l, r;
        cin >> l >> r;
        getline(cin, empty);
        ++events[l];
        --events[r + 1];
    }

    Ll balance = 0,
       prev = events.begin()->first,
       sum = 0;
    Ll const mod = 1000000007;
    for (auto it: events)
    {
        if (balance >= k) {
            sum += ((it.first - prev) * choose(balance, k)) % mod;
            sum %= mod;
        }

        balance += it.second;
        prev = it.first;
    }

    cout << sum << endl;
}
