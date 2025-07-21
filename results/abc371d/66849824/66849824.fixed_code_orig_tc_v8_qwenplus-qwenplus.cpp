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
    vector<ll> X(N), P(N + 1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Sort X with indices
    vector<pair<ll, int>> sorted_X(N);
    rep(i, N) sorted_X[i] = {X[i], i};
    sort(all(sorted_X));

    // Build prefix sums based on sorted X values
    vector<ll> prefix_sum(N + 1, 0);
    rep(i, N) prefix_sum[i + 1] = prefix_sum[i] + P[i + 1];

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;

        // Binary search to find the lower and upper bounds in X
        auto left = lower_bound(sorted_X.begin(), sorted_X.end(), make_pair(L, -1));
        auto right = upper_bound(sorted_X.begin(), sorted_X.end(), make_pair(R, N));

        int l_idx = left - sorted_X.begin();
        int r_idx = right - sorted_X.begin();

        // Sum of P[i+1] where X[i] is in [L, R]
        ll ans = prefix_sum[r_idx] - prefix_sum[l_idx];
        cout << ans << "\n";
    }

    return 0;
}