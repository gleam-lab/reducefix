#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];

    vector<ll> prefix(N + 1);
    prefix[0] = 0;
    rep(i, N) prefix[i + 1] = prefix[i] + P[i];

    vector<pair<ll, int>> sorted_X;
    rep(i, N) sorted_X.emplace_back(X[i], i);
    sort(all(sorted_X));

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        int left_idx = lower_bound(all(sorted_X), make_pair(L, 0)) - sorted_X.begin();
        int right_idx = upper_bound(all(sorted_X), make_pair(R, INT_MAX)) - sorted_X.begin();

        int l = (left_idx < N) ? sorted_X[left_idx].second : N;
        int r = (right_idx > 0) ? sorted_X[right_idx - 1].second : -1;

        if (r == -1 || l == N || l > r) {
            cout << 0 << '\n';
            continue;
        }

        ll ans = prefix[r + 1] - prefix[l];
        cout << ans << '\n';
    }

    return 0;
}