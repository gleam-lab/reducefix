#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<ll, int>> X(N); // value and original index
    vector<ll> P(N + 1, 0); // prefix sums

    for (int i = 0; i < N; ++i) {
        cin >> X[i].first;
        X[i].second = i;
    }
    for (int i = 0; i < N; ++i) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    sort(X.begin(), X.end());

    vector<ll> sorted_X(N);
    for (int i = 0; i < N; ++i) {
        sorted_X[i] = X[i].first;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll L, R;
        cin >> L >> R;

        int l = lower_bound(sorted_X.begin(), sorted_X.end(), L) - sorted_X.begin();
        int r = upper_bound(sorted_X.begin(), sorted_X.end(), R) - sorted_X.begin();

        ll ans = P[r] - P[l];
        cout << ans << '\n';
    }

    return 0;
}