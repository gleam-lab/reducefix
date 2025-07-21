#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int N = 2e5 + 9;
pair<int, int> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A values
        sort(a, a + n);
        
        // Create array with B values in A's sorted order
        vector<int> sorted_b(n);
        for (int i = 0; i < n; i++) {
            sorted_b[i] = b[a[i].second].first;
        }
        
        int ans = 1e18;
        priority_queue<int> pq;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (pq.size() < k) {
                pq.push(sorted_b[i]);
                sum += sorted_b[i];
            } else if (sorted_b[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(sorted_b[i]);
                sum += sorted_b[i];
            }
            
            if (pq.size() == k) {
                ans = min(ans, a[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}