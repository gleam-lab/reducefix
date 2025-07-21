#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_sum = sum + b[a[i].second];
            if (pq.size() == k - 1) {
                ans = min(ans, a[i].first * current_sum);
            }
            
            pq.push(b[a[i].second]);
            sum += b[a[i].second];
            
            if (pq.size() >= k) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}