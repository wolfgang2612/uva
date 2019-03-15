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
	int routes;
	cin >> routes;
	for (int i = 0;i < routes;i++)
	{
		int stops;
		cin >> stops;
		vector<int> nice(stops - 1);
		for (int j = 0;j < stops - 1;j++)
			cin >> nice[j];
		int maxsize = 0, size = 0, minind = stops - 1, ind = 0, max = 0, ans = 0;
		for (int j = 0;j < stops - 1;j++)
		{
			max += nice[j];
			size++;
			if (max > ans)
			{
				ans = max;
				minind = ind;
				maxsize = size;
			}
			else if (max == ans)
			{
				if (size > maxsize)
				{
					minind = ind;
					maxsize = size;
				}
				else if (size == maxsize)
					if (ind < minind)
						minind = ind;
			}
			else if (max < 0)
			{
				max = 0;
				ind = j + 1;
				size = 0;
			}
		}
		if(ans > 0)cout << "The nicest part of route " << i + 1 << " is between stops " << minind + 1 << " and " << minind + 1 + maxsize << "\n";
		else cout << "Route " << i + 1 << " has no nice parts" << "\n";
	}
	fclose(stdout);
	return 0;
}
