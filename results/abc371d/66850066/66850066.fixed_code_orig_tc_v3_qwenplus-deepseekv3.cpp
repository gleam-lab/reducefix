#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < N; ++i) cin >> P[i];

    // Create a vector of pairs (X_i, index) and sort by X_i
    vector<pair<ll, int>> x_index;
    for (int i = 0; i < N; ++i) {
        x_index.emplace_back(X[i], i);
    }
    sort(x_index.begin(), x_index.end());

    // Create prefix sums sorted by X_i
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + P[x_index[i].second];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        // Find first X_i >= L
        auto it_l = lower_bound(x_index.begin(), x_index.end(), make_pair(L, 0));
        // Find first X_i > R
        auto it_r = upper_bound(x_index.begin(), x_index.end(), make_pair(R, N));

        int l = distance(x_index.begin(), it_l);
        int r = distance(x_index.begin(), it_r);

        cout << (prefix_sum[r] - prefix_sum[l]) << '\n';
    }

    return 0;
}