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
        vector<pair<int,int>> items(n);
        for(int i = 0; i < n; ++i) cin >> items[i].f;
        for(int i = 0; i < n; ++i) cin >> items[i].s;
        
        // Sort items by A_i (first element of pair)
        sort(items.begin(), items.end());
        
        // Max heap to maintain smallest K-1 B_i values
        priority_queue<int> max_heap;
        int sum_B = 0;
        
        // Initialize with first K-1 elements
        for(int i = 0; i < k - 1; ++i) {
            sum_B += items[i].s;
            max_heap.push(items[i].s);
        }
        
        int ans = 1e18;
        
        // Try each possible maximum A_i from position k-1 to n-1
        for(int i = k - 1; i < n; ++i) {
            // Current item's A_i * (sum of B_i so far + current B_i)
            ans = min(ans, items[i].f * (sum_B + items[i].s));
            
            // If we can select more items to form other combinations
            if(i < n - 1) {
                // Add current item's B_i to the heap if it's smaller than max in heap or heap not full
                if(max_heap.size() < k - 1 || items[i].s < max_heap.top()) {
                    sum_B += items[i].s;
                    max_heap.push(items[i].s);
                    
                    if(max_heap.size() > k - 1) {
                        sum_B -= max_heap.top();
                        max_heap.pop();
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}