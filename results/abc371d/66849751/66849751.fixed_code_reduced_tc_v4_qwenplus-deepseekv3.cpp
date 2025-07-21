#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<ll> prefix_sum(N + 1, 0);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        prefix_sum[i + 1] = prefix_sum[i] + p;
    }

    vector<pair<int, int>> indexed_X;
    rep(i, N) indexed_X.emplace_back(X[i], i);
    sort(all(indexed_X));

    vector<int> sorted_X;
    for (auto& p : indexed_X) sorted_X.push_back(p.first);

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto lower = lower_bound(all(sorted_X), L);
        auto upper = upper_bound(all(sorted_X), R);
        int l = lower - sorted_X.begin();
        int r = upper - sorted_X.begin();
        int actual_l = (l < N) ? indexed_X[l].second : N;
        int actual_r = (r < N) ? indexed_X[r].second : N;
        if (actual_l >= actual_r) {
            cout << 0 << endl;
        } else {
            cout << prefix_sum[actual_r] - prefix_sum[actual_l] << endl;
        }
    }

    return 0;
}