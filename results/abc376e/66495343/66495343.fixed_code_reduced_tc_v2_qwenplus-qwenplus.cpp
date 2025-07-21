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
	
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		
		// Pair A_i and B_i and sort by A_i
		vector<PII> items(n);
		for(int i = 0; i < n; ++i)
			items[i] = {a[i], b[i]};
		
		sort(items.begin(), items.end());
		
		// Min-heap to keep the k smallest B_i values among the largest A_i's seen so far
		priority_queue<int, vector<int>, greater<int>> min_heap;
		int sum_b = 0;
		
		// First fill with the last k elements (smallest A values)
		for(int i = 0; i < k; ++i)
		{
			sum_b += items[i].se;
			min_heap.push(items[i].se);
		}
		
		int res = items[k-1].fi * sum_b;
		
		for(int i = k; i < n; ++i)
		{
			// Current item has larger A than all in heap
			int current_a = items[i].fi;
			int current_b = items[i].se;
			
			// If current B is smaller than max in heap, replace it
			if(!min_heap.empty() && current_b < min_heap.top())
			{
				sum_b -= min_heap.top();
				min_heap.pop();
				sum_b += current_b;
				min_heap.push(current_b);
			}
			
			// Update result with current maximum A in our set times total B sum
			res = min(res, current_a * sum_b);
		}
		
		cout << res << "\n";
	}
	
	return 0;
}