//
// http://codeforces.com/problemset/problem/701/C
//
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
vector<char> flats;

int main()
{
    cin >> n;
    flats.resize(n);
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        cin >> flats[i];
        s.insert(flats[i]);
    }

    int ans = flats.size();
    map<char, int> m; // pokemon type count
    for (int i = 0, j = 0; i < n && j < n;)
    {
        for (; j < n && m.size() < s.size(); j++)
        {
            m[flats[j]]++;
        }

        for (; m.size() == s.size(); i++)
        {
            if (m.size() == s.size() &&
                j - i < ans)
            {
                ans = j - i;
            }

            m[flats[i]]--;
            if (m[flats[i]] == 0)
            {
                m.erase(flats[i]);
            }
        }
    }

    cout << ans << endl;
}
