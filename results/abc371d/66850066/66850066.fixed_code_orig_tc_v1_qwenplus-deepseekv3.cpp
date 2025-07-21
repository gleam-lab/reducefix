#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
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

    // Create a vector of pairs (X_i, P_i) and sort by X_i
    vector<pair<ll, ll>> elements(N);
    for (int i = 0; i < N; ++i) {
        elements[i] = {X[i], P[i]};
    }
    sort(elements.begin(), elements.end());

    // Create prefix sums of P_i after sorting by X_i
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + elements[i].second;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        // Find first X_i >= L
        auto it_l = lower_bound(elements.begin(), elements.end(), make_pair(L, 0LL));
        int l = it_l - elements.begin();

        // Find first X_i > R
        auto it_r = upper_bound(elements.begin(), elements.end(), make_pair(R, LLONG_MAX));
        int r = it_r - elements.begin();

        cout << (prefix[r] - prefix[l]) << '\n';
    }

    return 0;
}