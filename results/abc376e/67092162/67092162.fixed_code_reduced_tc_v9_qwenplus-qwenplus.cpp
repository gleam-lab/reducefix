#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
typedef long long ll;

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
        for (int i = 0; i < n; ++i) cin >> items[i].first;  // A values
        for (int i = 0; i < n; ++i) cin >> items[i].second; // B values
        
        // Sort by A ascending
        sort(items.begin(), items.end());
        
        // Min-heap to keep track of smallest K B values
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum_b = 0;
        
        // Take first K elements
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }
        
        ll ans = (ll)items[k - 1].first * sum_b;
        
        // Try to improve by replacing largest B in set with smaller ones
        for (int i = k; i < n; ++i) {
            if (items[i].second < pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].second);
                sum_b += items[i].second;
                ans = min(ans, (ll)items[i].first * sum_b);
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}