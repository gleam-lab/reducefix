#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A_i
        sort(a.begin(), a.end());
        
        // Initialize the sliding window
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
        }
        
        int minProduct = inf;
        for (int i = k; i < n; i++) {
            minProduct = min(minProduct, static_cast<long long>(a[i].first) * sum);
            
            // Slide the window
            sum -= pq.top();
            pq.pop();
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
        }
        
        // Check the last window
        minProduct = min(minProduct, static_cast<long long>(a[n - 1].first) * sum);
        
        cout << minProduct << endl;
    }
    
    return 0;
}