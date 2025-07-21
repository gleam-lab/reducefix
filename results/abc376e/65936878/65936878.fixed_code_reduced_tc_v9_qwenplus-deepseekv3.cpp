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
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_b = 0;
        
        for (int i = 0; i < k - 1; ++i) {
            min_heap.push(v[i].second);
            sum_b += v[i].second;
        }
        
        int ans = LLONG_MAX;
        for (int i = k - 1; i < n; ++i) {
            int current_sum = sum_b + v[i].second;
            ans = min(ans, v[i].first * current_sum);
            
            if (k > 1) {
                if (!min_heap.empty() && min_heap.top() < v[i].second) {
                    sum_b -= min_heap.top();
                    min_heap.pop();
                    sum_b += v[i].second;
                    min_heap.push(v[i].second);
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}