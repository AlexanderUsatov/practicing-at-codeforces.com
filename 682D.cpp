#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

void getMaxDisjointSubstringLengthVec(vector<vector<size_t>> const substrLengthM,
                                      size_t const iBegin, size_t const iEnd,
                                      size_t const jBegin, size_t const jEnd,
                                      vector<int> &substringLengthVec)
{
    if (iBegin >= iEnd || jBegin >= jEnd)
    {
        return;
    }

    size_t iMaxSubstr = 0, jMaxSubstr = 0, lengthMax = 0;
    for (auto i = iBegin; i < iEnd; i++)
    {
        for (auto j = jBegin; j < jEnd; j++)
        {
            auto const length = substrLengthM[i][j];
            if (length > lengthMax)
            {
                lengthMax = length;
                iMaxSubstr = i;
                jMaxSubstr = j;
            }
        }
    }

    substringLengthVec.push_back(lengthMax);
    getMaxDisjointSubstringLengthVec(substrLengthM, iBegin, iMaxSubstr, jBegin, jMaxSubstr, substringLengthVec);
    getMaxDisjointSubstringLengthVec(substrLengthM, iMaxSubstr + lengthMax, iEnd, jMaxSubstr + lengthMax, jEnd, substringLengthVec);
}

int main()
{
    size_t unused, k = 2;
    cin >> unused >> unused >> k;
    string empty, s, t;
    getline(cin, empty);
    getline(cin, s);
    getline(cin, t);

    vector<vector<size_t>> subsrtingLengthM(s.length() + 1, vector<size_t>(t.length() + 1, 0));
    for (auto i = s.length(); i > 0; i--)
    {
        for (auto j = t.length(); j > 0; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                subsrtingLengthM[i - 1][j - 1] = subsrtingLengthM[i][j] + 1;
            }
        }
    }

    vector<int> substringLengthVec;
    getMaxDisjointSubstringLengthVec(subsrtingLengthM, 0, s.length(), 0, t.length(), substringLengthVec);

    sort(substringLengthVec.begin(), substringLengthVec.end());
    reverse(substringLengthVec.begin(), substringLengthVec.end());
    cout << accumulate(
        substringLengthVec.begin(),
        substringLengthVec.begin() + min(k, substringLengthVec.size()),
        0) << endl;
}
