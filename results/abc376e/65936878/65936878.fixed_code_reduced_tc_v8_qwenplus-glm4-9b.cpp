#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].s; // Read B_i first
        for (int i = 0; i < n; i++) cin >> v[i].f; // Then read A_i
        sort(begin(v), end(v));
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long ans = 1e18;
        long long sum_kb = 0; // Sum of B_i for the K largest A_i
        long long min_sum_b = 0; // Minimum sum of B_i in the priority queue
        
        // Calculate initial sum for the K largest A_i
        for (int i = n - 1; i >= n - k; i--) {
            sum_kb += v[i].s;
            min_sum_b += v[i].s;
            pq.push({v[i].s, i});
        }
        
        // Calculate minimum possible value
        for (int i = n - 1; i >= n - k; i--) {
            int max_a = v[i].f;
            long long current_value = max_a * sum_kb;
            ans = min(ans, current_value);
            // Update the priority queue
            long long removed_b = pq.top().f;
            min_sum_b -= removed_b;
            pq.pop();
            sum_kb -= removed_b;
            sum_kb += v[i].s;
            min_sum_b += v[i].s;
            pq.push({v[i].s, i});
        }
        
        cout << ans << '\n';
    }
    return 0;
}