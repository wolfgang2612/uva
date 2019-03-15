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

	int s, b, l, r;
	cin >> s >> b;

	while (s != 0 && b != 0)
	{
		vector<int> alive(s, 1), left(s), right(s);
		for (int i = 0;i < s;i++)
		{
			left[i] = i - 1;
			right[i] = i + 1;
		}
		left[0] = -1;
		right[s - 1] = -1;

		for (int i = 0;i < b;i++)
		{
			cin >> l >> r;
			for (int j = l - 1;j < r;j++)
				alive[j] = 0;

			if (l > 1 && left[l - 1] != -1)
			{
				cout << left[l - 1] + 1 << " ";
				right[left[l - 1]] = right[r - 1];
			}
			else cout << "* ";
			if (r < s && right[r - 1] != -1)
			{
				cout << right[r - 1] + 1 << "\n";
				left[right[r - 1]] = left[l - 1];
			}
			else cout << "*\n";
		}
		cout << "-\n";
		cin >> s >> b;
	}

	fclose(stdout);
	return 0;
}
