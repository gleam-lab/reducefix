#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        
        sort(a.begin(), a.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = INF;
        
        for (int i = 0; i < n; ++i) {
            if (pq.size() < k - 1) {
                pq.push(a[i].second);
                sum += a[i].second;
            } else {
                int current_max = a[i].first;
                int current_sum = sum + a[i].second;
                ans = min(ans, current_max * current_sum);
                
                if (!pq.empty() && a[i].second < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += a[i].second;
                    pq.push(a[i].second);
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}