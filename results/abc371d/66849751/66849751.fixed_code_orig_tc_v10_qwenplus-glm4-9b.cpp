#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

using ll = long long;
using Graph = vector<vector<int>>;
using IndexMap = map<ll, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N+1, 0), X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i+1];

    IndexMap x_to_ptr;
    ll current_sum = 0;
    for (int i = 0; i < N; ++i) {
        x_to_ptr.emplace(X[i], i);
        current_sum += X[i];
        P[i+1] = current_sum;
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);

        int l = X_l == x_to_ptr.begin() ? 0 : X_l->second;
        int r = X_r == x_to_ptr.end() ? N : X_r->second - 1;

        ll ans = P[r] - P[l];
        cout << ans << endl;
    }

    return 0;
}