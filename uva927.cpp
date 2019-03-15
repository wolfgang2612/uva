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
	long long int c, deg, d, k, n, result;
	cin >> c;

	for (int i = 0;i < c;i++)
	{
		cin >> deg;
		vector<int> poly(deg + 1);
		for (int j = 0;j < deg + 1;j++)
			cin >> poly[deg - j];
		cin >> d >> k;
		n = ceil((sqrt(1.0 + (double)(8 * (double)k / (double)d)) - 1.0) / 2.0);
		result = poly[0];
		for (int j = 1;j < deg + 1;j++)
			result = result*n + poly[j];
		cout << result << "\n";
	}
	fclose(stdout);
	return 0;
}
