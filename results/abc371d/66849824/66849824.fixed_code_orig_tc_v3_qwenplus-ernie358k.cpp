#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define pb(a) push_back(a)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l_it = x_to_ptr.lower_bound(L);
        int l = (X_l_it == x_to_ptr.end()) ? N - 1 : X_l_it->second;
        auto X_r_it = x_to_ptr.upper_bound(R);
        int r = (X_r_it == x_to_ptr.end()) ? N - 1 : (X_r_it->second - 1 >= 0) ? X_r_it->second - 1 : 0;
        // Adjust `r` to the rightmost valid index within the range
        while (r >= 0 && X[r] > R) --r;
        if (r < 0) r = 0;  // If no valid `r` found, use the first index
        // Ensure `l` is within bounds
        if (l >= N) l = N - 1;

        ll ans = P[r + 1] - P[l];
        cout << ans << endl;
    }
}