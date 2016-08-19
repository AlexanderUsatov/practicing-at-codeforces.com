//
// http://codeforces.com/contest/699/problem/B
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int x, y;

bool containsX(pair<int, int> const &xy)
{
    return xy.first == x;
}

bool containsY(pair<int, int> const &xy)
{
    return xy.second == y;
}

void YES()
{
    cout << "YES" << endl;
    cout << x + 1 << ' ' << y + 1 << endl;
}

void NO()
{
    cout << "NO" << endl;
}

int main()
{
    size_t cx, cy;
    cin >> cx >> cy;

    vector<int> xCnt(cx), yCnt(cy);
    vector<pair<int, int>> vs;
    for (size_t i = 0; i < cx; i++)
    {
        for (size_t j = 0; j < cy; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                xCnt[i]++;
                yCnt[j]++;
                vs.push_back(make_pair(i, j));
            }
        }
    }

    auto const itX = max_element(xCnt.cbegin(), xCnt.cend());
    auto const itY = max_element(yCnt.cbegin(), yCnt.cend());

    if (*itX > *itY)
    {
        x = distance(xCnt.cbegin(), itX);
        vs.erase(remove_if(vs.begin(), vs.end(), containsX), vs.end());
        if (vs.empty()) YES();
        else
        {
            y = vs.begin()->second;
            if (count_if(vs.begin(), vs.end(), containsY) == vs.size()) YES();
            else NO();
        }
    }
    else
    {
        y = distance(yCnt.cbegin(), itY);
        vs.erase(remove_if(vs.begin(), vs.end(), containsY), vs.end());
        if (vs.empty()) YES();
        else
        {
            x = vs.begin()->first;
            if (count_if(vs.begin(), vs.end(), containsX) == vs.size()) YES();
            else NO();
        }
    }
}
