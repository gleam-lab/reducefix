#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current = a[i].first;
            int current_sum = sum + a[i].second;
            if (pq.size() == k - 1) {
                ans = min(ans, current * current_sum);
            }
            pq.push(a[i].second);
            sum += a[i].second;
            if (pq.size() >= k) {
                sum -= pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}