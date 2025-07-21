#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];

    // Create a vector of pairs (X_i, index) and sort it based on X_i
    vector<pair<int, int>> sorted_X;
    rep(i, N) {
        sorted_X.emplace_back(X[i], i);
    }
    sort(all(sorted_X));

    // Create a prefix sum array based on the sorted indices
    vector<ll> prefix(N + 1, 0);
    rep(i, N) {
        prefix[i + 1] = prefix[i] + P[sorted_X[i].second];
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;

        // Find the first X_i >= L
        auto it_l = lower_bound(all(sorted_X), make_pair(L, -1));
        int l = it_l - sorted_X.begin();

        // Find the first X_i > R
        auto it_r = upper_bound(all(sorted_X), make_pair(R, INT_MAX));
        int r = it_r - sorted_X.begin();

        ll ans = prefix[r] - prefix[l];
        cout << ans << endl;
    }

    return 0;
}