//
// http://codeforces.com/contest/689/problem/E
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
	auto const input = vector<int>(istream_iterator<int>(cin), istream_iterator<int>());
	auto const n = input[0];
	auto const a = vector<int>(input.begin() + 1, input.begin() + 1 + n);
	auto const b = vector<int>(input.begin() + 1 + n, input.end());

	int ans = 0;
	deque<int> ad, bd;
	for (int i = 0, j = 0; i < n; i++)
	{
		for (; !ad.empty() && ad.back() <= a[i]; ad.pop_back());
		for (; !bd.empty() && bd.back() <= b[i]; bd.pop_back());
		ad.push_back(i);
		bd.push_back(i);

		for (; j <= i && !ad.empty() && !bd.empty() && a[ad.front()] > b[bd.front()];)
		{
			j++;
			for (; !ad.empty() && ad.front() < j; ad.pop_front());
			for (; !bd.empty() && bd.front() < j; bd.pop_front());
		}

		if (!ad.empty() && !bd.empty() && a[ad.front()] == b[bd.front()])
		{
			ans += min(ad.front(), bd.front()) - j + 2;
		}
	}

	cout << ans << endl;
}
