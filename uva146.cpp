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
	string id;
	cin >> id;

	while (id != "#")
	{
		if (next_permutation(id.begin(), id.end()))
			cout << id << "\n";
		else cout << "No Successor\n";
		cin >> id;
	}
	fclose(stdout);
	return 0;
}
