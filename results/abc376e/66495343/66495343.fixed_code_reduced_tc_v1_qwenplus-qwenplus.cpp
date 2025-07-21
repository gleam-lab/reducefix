#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int INF = 1e18;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		for (int i = 0; i < n; i++)
			cin >> b[i];

		// Pair A[i] and B[i], then sort by A[i]
		vector<PII> items(n);
		for (int i = 0; i < n; i++)
			items[i] = {a[i], b[i]};
		
		sort(items.begin(), items.end());

		// Minimize max_A * sum_B over subsets of size K
		// We maintain a window of K-1 smallest A's, then add one more to form K elements
		int res = numeric_limits<int>::max();
		int sum_b = 0;

		priority_queue<int> max_heap; // To keep track of the largest B values

		for (int i = 0; i < n; i++)
		{
			if (i < k - 1)
			{
				sum_b += items[i].second;
				max_heap.push(items[i].second);
			}
			else
			{
				// If heap has more than k-1 elements, remove the biggest
				if (max_heap.size() > k - 1)
				{
					sum_b -= max_heap.top();
					max_heap.pop();
				}

				sum_b += items[i].second;
				max_heap.push(items[i].second);

				res = min(res, items[i].first * sum_b);
			}
		}

		cout << res << "\n";
	}

	return 0;
}