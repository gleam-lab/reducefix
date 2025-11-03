#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int q;
	cin >> q;
	map<int, int> count;
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int x;
			cin >> x;
			count[x]++;
		}
		else if (a == 2)
		{
			int y;
			cin >> y;
			count[y]--;
			if (count[y] == 0) {
				count.erase(y);
			}
		}
		else if (a == 3)
		{
			cout << count.size() << endl;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}