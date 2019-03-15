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

	int N, n;
	int n0, n90, n180, n270;
	cin >> N >> n;

	while (N != 0 && n != 0)
	{
		vector<vector<char>> small, big, temp;
		vector<char> temp1;
		char temp2;

		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				cin >> temp2;
				temp1.push_back(temp2);
			}
			big.push_back(temp1);
			temp1.clear();
		}

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> temp2;
				temp1.push_back(temp2);
			}
			small.push_back(temp1);
			temp1.clear();
		}

		int ok = 1;
		n0 = n90 = n180 = n270 = 0;

		for (int i = 0;i < N - n + 1;i++)
		{
			for (int j = 0;j < N - n + 1;j++)
			{
				ok = 1;
				for (int k = 0;k < n && ok;k++)
					for (int l = 0;l < n && ok;l++)
						if (big[i + k][j + l] != small[k][l])
							ok = 0;
				if (ok)n0++;
			}
		}

		for (int i = 0;i < N - n + 1;i++)
		{
			for (int j = 0;j < N - n + 1;j++)
			{
				ok = 1;
				for (int k = 0;k < n && ok;k++)
					for (int l = 0;l < n && ok;l++)
						if (big[i + k][j + l] != small[n - l - 1][k])
							ok = 0;
				if (ok)n90++;
			}
		}

		for (int i = 0;i < N - n + 1;i++)
		{
			for (int j = 0;j < N - n + 1;j++)
			{
				ok = 1;
				for (int k = 0;k < n && ok;k++)
					for (int l = 0;l < n && ok;l++)
						if (big[i + k][j + l] != small[n - k - 1][n - l - 1])
							ok = 0;
				if (ok)n180++;
			}
		}

		for (int i = 0;i < N - n + 1;i++)
		{
			for (int j = 0;j < N - n + 1;j++)
			{
				ok = 1;
				for (int k = 0;k < n && ok;k++)
					for (int l = 0;l < n && ok;l++)
						if (big[i + k][j + l] != small[l][n - k - 1])
							ok = 0;
				if (ok)n270++;
			}
		}

		cout << n0 << " " << n90 << " " << n180 << " " << n270 << "\n";
		cin >> N >> n;
	}

	fclose(stdout);
	return 0;
}
