#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while (t--) {
        int n, k; 
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].f;
        for (int i = 0; i < n; ++i) cin >> v[i].s;
        
        // Sort by A_i in ascending order
        sort(v.begin(), v.end());
        
        priority_queue<int> pq;
        int sum_b = 0;
        int ans = 1e18;

        // We maintain a min-heap of size K
        multiset<int> min_heap;

        // First, fill the initial window of K elements
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].s;
            min_heap.insert(v[i].s);
        }

        // Now slide over the rest
        for (int i = k - 1; i < n; ++i) {
            sum_b += v[i].s;
            min_heap.insert(v[i].s);

            // Maintain only K elements using a multiset (min-heap style)
            while ((int)min_heap.size() > k) {
                int to_remove = *min_heap.rbegin(); // remove largest B_i to keep smallest K
                sum_b -= to_remove;
                auto it = min_heap.find(to_remove);
                if (it != min_heap.end()) min_heap.erase(it);
            }

            ans = min(ans, v[i].f * sum_b);

            // Remove current element for next iteration
            sum_b -= v[i].s;
            min_heap.erase(min_heap.find(v[i].s));
        }

        cout << ans << '\n';
    }

    return 0;
}