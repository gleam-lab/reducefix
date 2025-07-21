#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Create a sorted vector of pairs (X[i], i) instead of map
    vector<pair<ll, int>> x_idx(N);
    rep(i, N) {
        x_idx[i] = {X[i], i};
    }
    sort(all(x_idx));

    // Precompute prefix sums of P
    vector<ll> prefix_sum(N + 1);
    rep(i, N) {
        prefix_sum[i + 1] = prefix_sum[i] + P[i + 1] - P[i];
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Find the left and right boundaries using binary search
        auto left = lower_bound(all(x_idx), make_pair(L, -1));
        auto right = upper_bound(all(x_idx), make_pair(R, N));

        if (left == x_idx.end()) {
            cout << 0 << endl;
            continue;
        }

        int l_idx = left->second;
        int r_idx = (right == x_idx.begin()) ? 0 : (prev(right))->second + 1;

        // Calculate the sum from l_idx to r_idx in P array
        ll ans = P[r_idx] - P[l_idx];
        cout << ans << endl;
    }

    return 0;
}