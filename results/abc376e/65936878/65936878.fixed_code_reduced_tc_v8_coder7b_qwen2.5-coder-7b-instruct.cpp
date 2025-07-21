#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
signed main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<pair<int,int>> v(n);
		for(int i=0;i<n;i++) cin >> v[i].f; for(int i=0;i<n;i++) cin >> v[i].s;
		sort(begin(v),end(v));
		priority_queue<int, vector<int>, greater<int>> q; int x = 0;
		for(int i=0;i<k;i++) {q.push(v[i].s); x += v[i].s;}
		int ans = 1e18;
		for(int i=k;i<n;i++) {
			ans = min(ans, (x-v[q.top()]+v[i].s)*v[i].f);
			if(q.top() > v[i].s) {
				x -= q.top();
				q.pop(); q.push(v[i].s); 
			}
		}
		cout << ans << '\n';
	}
}