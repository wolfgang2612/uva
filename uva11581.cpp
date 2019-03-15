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

	int n, iter, sum;
	string lul;
	vector<int>temp(3, 0);
	vector<vector<int>> mat(3, temp), next(3, temp);

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		sum = 0;
		for (int j = 0;j < 3;j++)
		{
			cin >> lul;
			for (int k = 0;k < 3;k++)
			{
				mat[j][k] = lul[0] - '0';
				sum += mat[j][k];
			}
		}

		if (!sum)
			cout << "-1\n";
		else
		{
			iter = -1;
			sum = -1;

			while (sum)
			{
				sum = 0;
				sum += next[0][0] = (mat[0][1] + mat[1][0]) % 2;
				sum += next[0][1] = (mat[0][0] + mat[1][1] + mat[0][2]) % 2;
				sum += next[0][2] = (mat[0][1] + mat[1][2]) % 2;

				sum += next[1][0] = (mat[0][0] + mat[1][1] + mat[2][0]) % 2;
				sum += next[1][1] = (mat[0][1] + mat[1][0] + mat[1][2] + mat[2][1]) % 2;
				sum += next[1][2] = (mat[0][2] + mat[1][1] + mat[2][2]) % 2;

				sum += next[2][0] = (mat[1][0] + mat[2][1]) % 2;
				sum += next[2][1] = (mat[2][0] + mat[1][1] + mat[2][2]) % 2;
				sum += next[2][2] = (mat[2][1] + mat[1][2]) % 2;
				iter++;
				for (int j = 0;j < 3;j++)
					for (int k = 0;k < 3;k++)
						mat[j][k] = next[j][k];
			}
			cout << iter << "\n";
		}
	}
	fclose(stdout);
	return 0;
}
