#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f;
        for(int i=0;i<n;i++) cin >> v[i].s;
        
        // Sort by A_i ascending
        sort(v.begin(), v.end());
        
        // Min-heap to keep track of smallest B_i values in our current window
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        
        // Initialize with first K-1 elements
        for(int i = 0; i < k - 1; ++i) {
            sum_b += v[i].s;
            pq.push(v[i].s);
        }
        
        int ans = 1e18;
        
        // Slide window over the rest
        for(int i = k - 1; i < n; ++i) {
            // Consider including v[i] as the max A_i
            ans = min(ans, (sum_b + v[i].s) * v[i].f);
            
            // Prepare for next iteration: maintain K-1 smallest B's
            if(i < n - 1) {
                if(pq.size() < k - 1) {
                    sum_b += v[i].s;
                    pq.push(v[i].s);
                } else if(pq.top() > v[i].s) {
                    sum_b += v[i].s - pq.top();
                    pq.pop();
                    pq.push(v[i].s);
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}