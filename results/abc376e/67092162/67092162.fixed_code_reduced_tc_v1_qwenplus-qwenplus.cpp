#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].second;
        }
        
        // Sort by A value ascending
        sort(items.begin(), items.end());
        
        // Minimize sum * maxA
        // We keep a max-heap to maintain the K smallest B's among the selected A's
        priority_queue<int> pq;
        long long sumB = 0;
        long long result = 1e18; // A large initial value
        
        // First select K elements with smallest A values
        for (int i = 0; i < k; ++i) {
            sumB += items[i].second;
            pq.push(items[i].second);
        }
        
        result = (long long)items[k - 1].first * sumB;
        
        // Try replacing one element in the current selection with a higher A but potentially smaller B
        for (int i = k; i < n; ++i) {
            if (!pq.empty() && items[i].second < pq.top()) {
                sumB -= pq.top();
                pq.pop();
                sumB += items[i].second;
                pq.push(items[i].second);
                
                result = min(result, (long long)items[i].first * sumB);
            } else {
                // Since we're trying to minimize the product, and A is increasing,
                // once we can't improve by swapping, further elements won't help
                break;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}