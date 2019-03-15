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

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	freopen("op.txt", "w", stdout);

	int n, jol;

	cin >> n;

	while (!cin.eof())
	{
		vector<int> num(n);
		jol = 1;

		for (int i = 0;i < n;i++)
			cin >> num[i];

		map<int, int> val;

		for (int i = 0;i < n - 1;i++)
			val[abs(num[i + 1] - num[i])]++;

		for (int i = 1;i < n;i++)
		{
			if (!val[i])
			{
				cout << "Not jolly\n";
				jol = 0;
				break;
			}
		}
		if(jol)cout << "Jolly\n";
		cin >> n;
	}
	fclose(stdout);
	return 0;
}
