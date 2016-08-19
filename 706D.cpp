//
// http://codeforces.com/problemset/problem/706/D
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream input("input.txt"); cin.rdbuf(input.rdbuf());

  multiset<int> s;
  s.insert(0);

  int q; cin >> q;
  for (; q != 0; q--)
  {
    char c; int x; cin >> c >> x;
    switch (c)
    {
    case '+':
      s.insert(x);
      break;
    case '-':
      s.erase(s.find(x));
      break;
    default:
      int a = 0;
      for (int i = 30; i >= 0; i--)
      {
        a |= (~x & (1 << i));
        auto const it = s.lower_bound(a);
        if (it == s.end() || *it >= a + (1 << i))
        {
          a ^= (1 << i);
        }
      }

      cout << (a ^ x) << endl;
      break;
    }
  }
}
