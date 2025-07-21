#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f; for(int i=0;i<n;i++) cin >> v[i].s;
        
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        for(int i=0;i<k;i++) {
            pq.push(v[i].s);
            sum_b += v[i].s;
        }
        
        int ans = INT_MAX;
        for(int i=k;i<n;i++) {
            int max_a = v[i].f;
            int sum_b_new = sum_b - pq.top() + v[i].s;
            pq.pop();
            pq.push(v[i].s);
            
            ans = min(ans, max_a * sum_b_new);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}