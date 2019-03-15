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

bool minf(long long int a, long long int b)
{
	return a > b;
}

bool maxf(long long int a, long long int b)
{
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("op.txt", "w", stdout);
	long long int temp, median = 0;
	vector<long long int>minh, maxh;

	cin >> temp;
	while (!cin.eof())
	{
		if (minh.size() == maxh.size())
		{
			if (temp < median)
			{
				maxh.push_back(temp);
				push_heap(maxh.begin(), maxh.end(), maxf);
				median = maxh.front();
			}
			else
			{
				minh.push_back(temp);
				push_heap(minh.begin(), minh.end(), minf);
				median = minh.front();
			}
		}

		else if (maxh.size() > minh.size())
		{
			if (temp < median)
			{
				minh.push_back(maxh.front());
				make_heap(minh.begin(), minh.end(), minf);
				pop_heap(maxh.begin(), maxh.end(), maxf);
				maxh.erase((--maxh.end()));

				maxh.push_back(temp);
				push_heap(maxh.begin(), maxh.end(), maxf);
			}
			else
			{
				minh.push_back(temp);
				push_heap(minh.begin(), minh.end(), minf);
			}
			median = (minh.front() + maxh.front()) / 2;
		}

		else
		{
			if (temp < median)
			{
				maxh.push_back(temp);
				push_heap(maxh.begin(), maxh.end(), maxf);
			}

			else
			{
				maxh.push_back(minh.front());
				make_heap(maxh.begin(), maxh.end(), maxf);
				pop_heap(minh.begin(), minh.end(), minf);
				minh.erase((--minh.end()));

				minh.push_back(temp);
				push_heap(minh.begin(), minh.end(), minf);
			}
			median = (minh.front() + maxh.front()) / 2;
		}
		cout << median << "\n";
		cin >> temp;
	}

	fclose(stdout);
	return 0;
}
