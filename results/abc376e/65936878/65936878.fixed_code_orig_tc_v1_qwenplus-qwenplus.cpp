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
        for (int i = 0; i < n; ++i) cin >> v[i].f;
        for (int i = 0; i < n; ++i) cin >> v[i].s;

        // Sort by A_i in ascending order
        sort(v.begin(), v.end());

        priority_queue<int> max_heap; // to maintain the K largest B values
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        // Precompute prefix of smallest K-1 elements
        multiset<int> top_k_minus_1;
        int sum_k_minus_1 = 0;

        for (int i = 0; i < n; ++i) {
            if (i < k - 1) {
                sum_k_minus_1 += v[i].s;
                top_k_minus_1.insert(v[i].s);
            } else {
                // Try including v[i] as max A_i
                sum_b = sum_k_minus_1 + v[i].s;
                res = min(res, v[i].f * sum_b);

                // Maintain top k-1 B's using multiset
                if (v[i].s > *(top_k_minus_1.begin())) {
                    sum_k_minus_1 -= *(top_k_minus_1.begin());
                    top_k_minus_1.erase(top_k_minus_1.find(*(top_k_minus_1.begin())));
                    top_k_minus_1.insert(v[i].s);
                    sum_k_minus_1 += v[i].s;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}