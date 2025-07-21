#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    vector<pair<ll, ll>> pairs;
    for (int i = 0; i < N; ++i) {
        pairs.emplace_back(X[i], P[i]);
    }
    sort(pairs.begin(), pairs.end());

    vector<ll> sorted_X(N), sorted_P(N);
    for (int i = 0; i < N; ++i) {
        sorted_X[i] = pairs[i].first;
        sorted_P[i] = pairs[i].second;
    }

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_P[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        auto it_l = lower_bound(sorted_X.begin(), sorted_X.end(), L);
        auto it_r = upper_bound(sorted_X.begin(), sorted_X.end(), R);
        int l = it_l - sorted_X.begin();
        int r = it_r - sorted_X.begin();
        ll ans = prefix[r] - prefix[l];
        cout << ans << '\n';
    }

    return 0;
}