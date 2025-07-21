#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].f;
        for (int i = 0; i < n; i++) cin >> v[i].s;
        
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_B = 0;
        
        for (int i = 0; i < k - 1; i++) {
            min_heap.push(v[i].s);
            sum_B += v[i].s;
        }
        
        int ans = LLONG_MAX;
        
        for (int i = k - 1; i < n; i++) {
            int current_sum = sum_B + v[i].s;
            ans = min(ans, v[i].f * current_sum);
            
            if (!min_heap.empty() && min_heap.top() < v[i].s) {
                sum_B -= min_heap.top();
                min_heap.pop();
                min_heap.push(v[i].s);
                sum_B += v[i].s;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}