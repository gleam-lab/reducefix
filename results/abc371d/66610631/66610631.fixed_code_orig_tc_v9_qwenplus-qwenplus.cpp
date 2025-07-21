#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<LL> prefix_b(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        prefix_b[i + 1] = prefix_b[i] + b[i];
    }
    
    int m;
    cin >> m;
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Precompute prefix sums of b
    vector<LL> c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i - 1];
    }

    for (const auto& [l, r] : queries) {
        // Find the first index in a >= l
        auto l_it = lower_bound(a.begin(), a.end(), l);
        // Find the first index in a > r
        auto r_it = upper_bound(a.begin(), a.end(), r);

        int left_idx = distance(a.begin(), l_it);
        int right_idx = distance(a.begin(), r_it);

        LL sum = c[right_idx] - c[left_idx];
        cout << sum << '\n';
    }

    return 0;
}