#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

using namespace std;


struct comp {
	bool operator()(pair<int, pair<int, int>> const & a,pair<int, pair<int, int>> const & b) const noexcept
	{
		if(a.second.second != b.second.second)return a.second.second > b.second.second;
		else return a.second.first > b.second.first;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("op.txt", "w", stdout);

	string s;
	cin >> s;
	int key, period, k, time;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> q;

	while (s != "#")
	{
		cin >> key >> period;
		q.push(make_pair(period, make_pair(key, period)));
		cin >> s;
	}

	cin >> k;
	for (int i = 0;i < k;i++)
	{
		cout << q.top().second.first << "\n";
		period = q.top().first;
		key = q.top().second.first;
		time = q.top().second.second;
		q.pop();
		q.push(make_pair(period, make_pair(key, time + period)));
	}

	fclose(stdout);
	return 0;
}
