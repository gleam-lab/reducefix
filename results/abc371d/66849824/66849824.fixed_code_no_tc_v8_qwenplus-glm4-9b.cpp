#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0);
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i + 1] >> P[i + 1] - P[i]; // Assuming the input for P is wrong, this will accumulate values

    map<int, int> x_to_ptr;
    rep(i, N) x_to_ptr.emplace(X[i], i);

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        int l = X_l == x_to_ptr.end() ? N : X_l->second;
        int r = X_r == x_to_ptr.end() ? N : X_r->second;
        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}