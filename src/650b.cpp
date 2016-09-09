#include <bits/stdc++.h>
using namespace std;

int n, a, b, T;
char p[500000];
int sl[500000] = {}, sr[500000] = {};

int slide_left()
{
    sl[0] = 1;
    if (p[0] == 'w')
        sl[0] += b;
    if (sl[0] > T)
        return 0;

    for (int i = n - 1; i > 0; i--)
    {
        sl[i] = sl[(i + 1)%n] + a + 1;
        if (p[i] == 'w')
            sl[i] += b;
        if (sl[i] > T)
            return n - i;
    }

    return n;
}

int slide_right()
{
    sr[0] = 1;
    if (p[0] == 'w')
        sr[0] += b;
    if (sr[0] > T)
        return 0;

    for (int i = 1; i < n; i++)
    {
        sr[i] = sr[i - 1] + a + 1;
        if (p[i] == 'w')
            sr[i] += b;
        if (sr[i] > T)
            return i;
    }

    return n;
}

int slide_left_right(int l)
{
    int r = 1, ret = 0;
    for (; l < n - 1; l++)
    {
        auto t = sl[l] + (n - l)*a + sr[r] - 1;
        for (; t > T && l < n - 1; l++, t = sl[l] + (n - l)*a + sr[r] - 1);
        if (t > T && l == n - 1)
            break;

        for (; r < n - 2 && sl[l] + (n - l)*a + sr[r + 1] - 1 <= T; r++, t = sl[l] + (n - l)*a + sr[r] - 1);
        ret = max(ret, n - l + r + 1);
    }

    return ret;
}

int slide_right_left(int r)
{
    int l = n - 1, ret = 0;
    for (; r > 0; r--)
    {
        auto t = sr[r] + r*a + sl[l] - 1;
        for (; t > T && r > 1; r--, t = sr[r] + r*a + sl[l] - 1);
        if (t > T && r == 1)
            break;

        for (; l > 1 && sr[r] + r*a + sl[l - 1] - 1 <= T; l--, t = sr[r] + r*a + sl[l] - 1);
        ret = max(ret, n - l + r + 1);
    }

    return ret;
}

int main()
{
  //ifstream input("input.txt");
  //cin.rdbuf(input.rdbuf());

  cin >> n >> a >> b >> T;
  for (int i = 0; i < n; i++) cin >> p[i];

  auto const l = slide_left();
  auto const r = slide_right();
  auto lr = 0, rl = 0;
  if (l != 0)
      lr = max(l, slide_left_right(n - l + 1));
  if (r != 0)
      rl = max(r, slide_right_left(r - 1));

  cout << min(n, max(
      max(l, r),
      max(lr, rl))) << endl;
}
