#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].ff;
        for(int i = 0; i < n; i++) cin >> v[i].ss;
        
        sort(v.begin(), v.end());
        
        priority_queue<int> pq;
        long long sum = 0;
        for(int i = 0; i < k; i++) {
            pq.push(-v[i].ss);
            sum += v[i].ss;
        }
        
        long long ans = 1LL * v[k - 1].ff * sum;
        
        for(int i = k; i < n; i++) {
            sum -= pq.top();
            pq.pop();
            
            pq.push(-v[i].ss);
            sum += v[i].ss;
            
            ans = min(ans, 1LL * v[i].ff * sum);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}