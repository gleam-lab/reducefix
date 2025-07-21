#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].f;
        for(int i = 0; i < n; i++) cin >> v[i].s;
        
        // Sort based on A[i] in descending order and B[i] in ascending order
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.f == b.f ? a.s < b.s : a.f > b.f;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        for(int i = 0; i < k - 1; i++) {
            pq.push(v[i].s);
            sum_b += v[i].s;
        }
        
        int ans = 1e18;
        for(int i = k - 1; i < n; i++) {
            int max_a = v[i].f;
            int sum_b_current = sum_b + v[i].s;
            
            if(!pq.empty()) {
                sum_b_current -= pq.top();
                sum_b_current += v[i].s;
                pq.pop();
                pq.push(v[i].s);
            }
            
            ans = min(ans, max_a * sum_b_current);
        }
        
        cout << ans << '\n';
    }
    return 0;
}