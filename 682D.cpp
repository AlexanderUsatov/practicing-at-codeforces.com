//
// Вернувшись из леса, Алёна начала читать книгу. Ее взгляд упал на строки s и t, 
// длины которых равняются n и m соответственно. Как обычно, Алёне быстро наскучило 
// читать, и она решила переключить внимание на строки s и t, которые показались ей 
// очень похожими.
// 
// У Алёны есть любимое целое положительное число k, но, так как она еще маленькая, 
// k не превосходит 10. Девочка хочет выбрать k непересекающихся подстрок строки s, 
// таких что они встречаются в строке t как непересекающиеся подстроки в том же порядке, 
// что и в строке s, а их суммарная длина максимальна.
// 
// Формально, Алёна хочет найти последовательность из k непустых строк p1, p2, p3, 
// ..., pk, такую что:
// 
// строка s представима в виде конкатенации a1p1a2p2... akpkak + 1, где a1, a2, 
// ..., ak + 1 — произвольная последовательность строк (возможно, пустых);
// строка t представима в виде конкатенации b1p1b2p2... bkpkbk + 1, где b1, b2, 
// ..., bk + 1 — произвольная последовательность строк (возможно, пустых);
// сумма длин строк последовательности максимальна среди всех возможных вариантов.
// Помогите Алёне справиться с непростой задачей и найти хотя бы суммарную длину 
// строк искомой последовательности.
// 
// Подстрока строки — это непрерывная последовательность букв строки.
// 
// Входные данные
// В первой строке входных данных содержатся три целых числа n, m, k (1 ≤ n, m ≤ 
// 1000, 1 ≤ k ≤ 10) — длина строки s, длина строки t и любимое число Алёны соответственно.
// 
// Во второй строке входных данных содержится строка s, состоящая из строчных букв 
// латинского алфавита.
// 
// В третьей строке входных данных задана строка t, состоящая из строчных букв латинского 
// алфавита.
// 
// Выходные данные
// В единственной строке выведите одно целое неотрицательное число — суммарную длину 
// строк в искомой последовательности.
// 
// Гарантируется, что существует хотя бы одна искомая последовательность строк.
//

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
