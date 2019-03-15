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

	//freopen("op.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		int k, b;
		char a;
		cin >> k;
		map<char, int> val;
		for (int j = 0;j < k;j++)
		{
			cin >> a >> b;
			val[a] = b;
		}
		long long int m, price = 0;
		cin >> m;
		for (int j = 0;j < m+1;j++)
		{
			char kek[10100];
			cin.getline(kek, 10100);
			for (int x = 0;x < strlen(kek);x++)
				price += val[kek[x]];
		}
		cout << std::fixed << std::setprecision(2) << ((double)price) / 100.0 << "$\n";
	}
	//fclose(stdout);
	return 0;
}
