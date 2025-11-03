#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int q;
	cin >> q;
	map<int, int> freq;
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int x;
			cin >> x;
			freq[x]++;
		}
		else if (a == 2)
		{
			int y;
			cin >> y;
			freq[y]--;
			if (freq[y] == 0) {
				freq.erase(y);
			}
		}
		else if (a == 3)
		{
			cout << freq.size() << endl;
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
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}