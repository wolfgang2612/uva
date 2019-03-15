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
	long long int sz, p, n, side, step;
	cin >> sz >> p;

	while (sz != 0 && p != 0)
	{
		n = ceil((sqrt(p) - 1.0) / 2.0);
		if (n)
		{
			side = (((2 * n + 1)*(2 * n + 1)) - p) / (2 * n);
			step = (((2 * n + 1)*(2 * n + 1)) - p) % (2 * n);

			switch (side)
			{
			case 0:
				cout << "Line = " << ceil(sz / 2.0) + n - step << ", column = " << ceil(sz / 2.0) + n << ".\n";
				break;
			case 1:
				cout << "Line = " << ceil(sz / 2.0) - n << ", column = " << ceil(sz / 2.0) + n - step << ".\n";
				break;
			case 2:
				cout << "Line = " << ceil(sz / 2.0) - n + step << ", column = " << ceil(sz / 2.0) - n << ".\n";
				break;
			case 3:
				cout << "Line = " << ceil(sz / 2.0) + n << ", column = " << ceil(sz / 2.0) - n + step << ".\n";
				break;
			default:
				break;
			}
		}
		else
			cout << "Line = " << ceil(sz / 2.0) << ", column = " << ceil(sz / 2.0) << ".\n";
		cin >> sz >> p;
	}
	fclose(stdout);
	return 0;
}
