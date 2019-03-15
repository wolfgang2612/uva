#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <Bits.h>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count, orig, op;
	bitset<35> num, out;
	vector<int> temp(35);
	int flag;

	cin >> n;
	orig = n;
	while (n != EOF)
	{
		num.reset();
		count = 0;
		flag = -1;
		op = 0;
		while (n)
		{
			temp.push_back(n % 2);
			n /= 2;
			count++;
		}

		for (int i = count - 1;i >= 0;i--)
			num[count - i - 1] = temp[i];

		if (orig < 0)
		{
			for (int i = 0;i < count;i++)
			{
				if (num[i] && flag == -1)flag = i;
				else if (flag >= 0)num ^= 1 << i;
			}
		}

		for (int i = 0;i < ((count + 7) / 8);i++)
		{
			if ((i + 1) * 8 < num.size())
			{
				for (int k = 0;k < 8;k++)
					out[out.size() - 1 - (i + 1) * 8 + k] = num[(i + 1) * 8 + k];
			}
			else
			{
				for (int k = 0;k < 8 - count % 8; k++)
					out[out.size() - 1 - (i + 1) * 8 + k + count % 8] = 0;
				for (int k = 0;k < count % 8;k++)
					out[out.size() - 1 - (i + 1) * 8 + k] = num[(i + 1) * 8 + k];
			}
		}
		cin >> n;
		orig = n;

		flag = -1;

		if (out[out.size() - 1] == 0)
		{
			for (int i = 0;i < out.size();i++)
				op += pow(2, out[i] * i);
			cout << op << "\n";
		}
		else
		{
			for (int i = 0;i < out.size();i++)
			{
				if (out[i] == 1 && flag == -1)
				{
					flag = i;
					continue;
				}
				if (flag >= 0)
					out ^= 1 << i;
			}
		}

		for (int i = 0;i < out.size();i++)
			op += pow(2, out[i] * i);
		cout << -1 * op << "\n";
	}
	return 0;
}
