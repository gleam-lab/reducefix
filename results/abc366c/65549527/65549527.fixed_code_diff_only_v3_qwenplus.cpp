#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int q;
	cin >> q;
	map<int, int> count; // tracks frequency of each integer in the bag
	
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
			int x;
			cin >> x;
			count[x]--;
			if (count[x] == 0) {
				count.erase(x);
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