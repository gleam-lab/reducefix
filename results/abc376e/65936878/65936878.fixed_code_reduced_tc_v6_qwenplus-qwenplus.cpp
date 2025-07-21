#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; i++) cin >> items[i].f;
        for (int i = 0; i < n; i++) cin >> items[i].s;
        
        // Sort items by A_i (first element of pair)
        sort(items.begin(), items.end());
        
        // Max heap to maintain the K smallest B_i values
        priority_queue<int> max_heap;
        int sum_b = 0;
        
        // Initialize with first K items
        for (int i = 0; i < k; i++) {
            sum_b += items[i].s;
            max_heap.push(items[i].s);
        }
        
        // The best value with the first K items
        int ans = items[k - 1].f * sum_b;
        
        // Try including better combinations
        for (int i = k; i < n; i++) {
            if (items[i].s < max_heap.top()) {
                sum_b -= max_heap.top();
                max_heap.pop();
                sum_b += items[i].s;
                max_heap.push(items[i].s);
                
                ans = min(ans, items[i].f * sum_b);
            }
        }
        
        cout << ans << '\n';
    }
}