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

bool comp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.second < b.second.second;
}

bool comp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first > b.second.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("op.txt", "w", stdout);

	long long int n;
	cin >> n;

	string s;
	getline(cin, s);
	getline(cin, s);

	for (int i = 0;i < n;i++)
	{
		vector<int>problems(100,-1), final(100,0);
		vector<vector<int>> time(100,vector<int>(9,INT_MAX)), inc(100, vector<int>(9, 0));
		vector<pair<int, pair<int, int>>> op;
		while (getline(cin, s))
		{
			if (!s.empty())
			{
				string::size_type sz;
				int a = stoi(s, &sz);
				s = s.substr(sz);
				int b = stoi(s, &sz);
				s = s.substr(sz);
				int c = stoi(s, &sz);
				s = s.substr(sz);
				if (problems[a - 1] == -1)problems[a - 1] = 0;
				if (s[1] == 'I' && c < time[a - 1][b - 1])
					inc[a - 1][b - 1]++;
				if (s[1] == 'C')
				{
					if(time[a - 1][b - 1] == INT_MAX)problems[a - 1]++;
					if (c < time[a - 1][b - 1])
					{
						if (time[a - 1][b - 1] != INT_MAX)final[a - 1] -= time[a - 1][b - 1];
						time[a - 1][b - 1] = c;
						final[a - 1] += c;
					}
				}
			}
			else break;
		}

		for (int i = 0;i < 100;i++)
			for (int j = 0;j < 9;j++)
				if (time[i][j] != INT_MAX)
					final[i] += 20 * inc[i][j];

		if (s.empty())
		{
			for (int i = 0;i < 100;i++)
			{
				if (problems[i] > -1)
				{
					pair<int, int> tp = make_pair(problems[i], final[i]);
					op.push_back(make_pair(i + 1, tp));
				}
			}
			stable_sort(op.begin(), op.end(), comp1);
			stable_sort(op.begin(), op.end(), comp2);

			for (vector<pair<int, pair<int, int>>>::iterator iter = op.begin(); iter != op.end(); ++iter)
				cout << (*iter).first << " " << (*iter).second.first << " " << (*iter).second.second << "\n";
		}

		if(i != n-1)cout << "\n";
	}

	fclose(stdout);
	return 0;
}
