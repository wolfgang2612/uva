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
	int f, r;

	cin >> f >> r;

	while (f != 0)
	{
		vector<int>front(f), rear(r);
		for (int i = 0;i < f;i++)
			cin >> front[i];
		for (int i = 0;i < r;i++)
			cin >> rear[i];
		vector<double> ratio;
		for (int i = 0;i < r;i++)
			for (int j = 0;j < f;j++)
				ratio.push_back((double)rear[i]/(double)front[j]);
		sort(ratio.begin(), ratio.end());
		double max = 0;
		for (int i = 0;i < f*r - 1;i++)
			if (max < (double)ratio[i + 1] / (double)ratio[i])
				max = (double)ratio[i + 1] / (double)ratio[i];
		cout << fixed << setprecision(2) << max << "\n";
		cin >> f;
		if (!f)break;
		else cin >> r;
	}
	fclose(stdout);
	return 0;
}
