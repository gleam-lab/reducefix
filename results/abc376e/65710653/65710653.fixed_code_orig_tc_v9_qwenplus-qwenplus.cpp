#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> AB(N);
    for (auto &x : AB) cin >> x.first;
    for (auto &x : AB) cin >> x.second;

    // Sort by A[i]
    sort(AB.begin(), AB.end());

    // Use multiset to keep track of B values
    multiset<ll> b_values;
    ll sum_b = 0;

    // Initialize first K elements
    for (int i = 0; i < K; ++i) {
        b_values.insert(AB[i].second);
        sum_b += AB[i].second;
    }

    ll result = sum_b * AB[K - 1].first;

    // Slide the window
    for (int i = K; i < N; ++i) {
        // Remove the B value with highest A[i] currently in set
        // Since multiset stores B values only, we can't directly compare A values
        // So, we must use a max-heap or manually find the largest B to remove
        auto it = prev(b_values.end()); // points to largest B
        sum_b -= *it;
        b_values.erase(it);

        // Add new B value
        b_values.insert(AB[i].second);
        sum_b += AB[i].second;

        // Update result
        result = min(result, sum_b * AB[i].first);
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}