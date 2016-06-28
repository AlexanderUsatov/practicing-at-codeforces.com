#include <vector>
#include <string>
#include <iostream>

using namespace std;

size_t getMaxSubstring(vector<vector<size_t>> const &arr,
                       size_t &iBegin, size_t &iEnd,
                       size_t &jBegin, size_t &jEnd)
{
    size_t iBest = 0, jBest = 0, lengthMax = 0;
    for (auto i = iBegin; i < iEnd; i++)
    {
        for (auto j = jBegin; j < jEnd; j++)
        {
            if (arr[i][j] > lengthMax)
            {
                lengthMax = arr[i][j];
                iBest = i;
                jBest = j;
            }
        }
    }

    iBegin = iBest;
    iEnd = iBegin + lengthMax;
    jBegin = jBest;
    jEnd = jBegin + lengthMax;

    return lengthMax;
}

int main()
{
    size_t n, m, k;
    cin >> n >> m >> k;
    string s, t;
    getline(cin, s);
    getline(cin, t);

    vector<vector<size_t>> arr(s.length() + 1, vector<size_t>(t.length() + 1, 0));
    for (auto i = s.length(); i > 0; i--)
    {
        for (auto j = t.length(); j > 0; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                arr[i - 1][j - 1] = arr[i][j] + 1;
            }
        }
    }

    // TODO:
    //
}
