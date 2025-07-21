#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first;
        for (int i = 0; i < n; ++i) cin >> v[i].second;
        sort(v.begin(), v.end());
        
        priority_queue<int> pq; // max-heap to store the smallest (k-1) B_i's
        int sum = 0;
        
        for (int i = 0; i < k - 1; ++i) {
            pq.push(v[i].second);
            sum += v[i].second;
        }
        
        int ans = LLONG_MAX;
        for (int i = k - 1; i < n; ++i) {
            int current_sum = sum + v[i].second;
            ans = min(ans, v[i].first * current_sum);
            
            if (!pq.empty() && v[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += v[i].second;
                pq.push(v[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}