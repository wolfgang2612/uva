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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("op.txt", "w", stdout);
	long long int n, total;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	getline(cin, s);

	for (int i = 0;i < n;i++)
	{
		total = 0;
		map<string,long long int> tree;
		vector<string> name;
		while (!s.empty())
		{
			if (!tree[s])name.push_back(s);
			tree[s]++;
			total++;
			getline(cin, s);
		}
		sort(name.begin(), name.end());
		for (vector<string>::iterator j = name.begin();j != name.end();j++)
			cout << *j << " " << fixed << setprecision(4) << (double)tree[(*j)] / (double)total * 100.0 << "\n";
		if (i != n - 1)cout << "\n";
		getline(cin, s);
	}
	fclose(stdout);
	return 0;
}
