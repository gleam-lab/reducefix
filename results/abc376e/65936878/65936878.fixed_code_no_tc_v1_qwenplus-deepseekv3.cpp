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
        
        priority_queue<int> pq; // max heap to store the smallest K-1 B_i's
        int sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += v[i].s;
            pq.push(v[i].s);
        }
        
        int ans = LLONG_MAX;
        for (int i = k - 1; i < n; i++) {
            int current_sum = sum + v[i].s;
            ans = min(ans, current_sum * v[i].f);
            
            if (!pq.empty() && v[i].s < pq.top()) {
                sum -= pq.top();
                sum += v[i].s;
                pq.pop();
                pq.push(v[i].s);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}