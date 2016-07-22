//
// http://codeforces.com/problemset/problem/697/B
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, d;
    int b;
    char ch;
    for (cin >> ch; ch != '.'; a.push_back(ch), cin >> ch);
    for (cin >> ch; ch != 'e'; d.push_back(ch), cin >> ch);
    cin >> b;

    for (;b != 0; b--)
    {
        if (d.size() != 0)
        {
            a.push_back(d.front());
            d.erase(0, 1);
        }
        else
        {
            a.push_back('0');
        }
    }

    for (; a.size() > 1 && a[0] == '0'; a.erase(0, 1));

    cout << a;
    if (!d.empty() && d != "0")
    {
        cout << '.' << d;
    }

    cout << endl;
}
