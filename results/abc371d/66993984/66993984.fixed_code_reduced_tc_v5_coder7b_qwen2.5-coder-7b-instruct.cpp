#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;
    
    vector<pair<int, int>> villages(n); // Store villages as pairs of (coordinate, population)
    for (int i = 0; i < n; ++i) {
        cin >> villages[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> villages[i].second;
    }

    sort(villages.begin(), villages.end()); // Sort villages based on their coordinates

    vector<long long> prefix_sum(n + 1); // Prefix sum array to store cumulative population
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + villages[i].second;
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        auto it_l = lower_bound(villages.begin(), villages.end(), make_pair(l, 0));
        auto it_r = upper_bound(villages.begin(), villages.end(), make_pair(r, INT_MAX));

        int idx_l = it_l - villages.begin();
        int idx_r = it_r - villages.begin();

        if (idx_l == n || villages[idx_l].first > r) --idx_l; // Adjust index if out of bounds
        if (idx_r == 0 || villages[idx_r - 1].first < l) ++idx_r; // Adjust index if out of bounds

        if (idx_l >= idx_r) {
            cout << 0 << '\n'; // No villages in range [l, r]
        } else {
            cout << prefix_sum[idx_r] - prefix_sum[idx_l] << '\n';
        }
    }

    return 0;
}