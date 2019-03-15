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
	string s;

	getline(cin, s);

	while (!s.empty())
	{
		list<char> xd, temp;
		int dir = 0;
		for (int i = 0;i < s.length();i++)
		{
			if (s[i] == '[')
			{
				if (dir)
				{
					xd.splice(xd.begin(), temp);
					temp.clear();
				}
				dir = 1;
			}
			else if (s[i] == ']')
			{
				if (dir)
				{
					xd.splice(xd.begin(), temp);
					temp.clear();
				}
				dir = 0;
			}
			else
			{
				if (!dir)
				{
					xd.splice(xd.begin(), temp);
					temp.clear();
					xd.push_back(s[i]);
				}
				else temp.push_back(s[i]);
			}
		}
		if (!temp.empty())
		{
			xd.splice(xd.begin(), temp);
			temp.clear();
		}
		for (list<char>::iterator i = xd.begin();i != xd.end();i++)
			cout << *i;
		cout << "\n";
		getline(cin, s);
	}
	fclose(stdout);
	return 0;
}
