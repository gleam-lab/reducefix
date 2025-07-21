#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];

    // Calculate prefix sums of population
    rep(i, 1, N) P[i] += P[i-1];

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        // Find the first element not less than L
        auto it_L = lower_bound(all(X), L);
        // Find the first element greater than R
        auto it_R = upper_bound(all(X), R);
        
        // If no elements are found or they are out of bounds
        if (it_L == end(X) || *it_L > R) {
            cout << 0 << '\n';
        } else if (it_R == begin(X)) {
            cout << P[it_L - begin(X)] << '\n';
        } else {
            cout << P[it_R - begin(X) - 1] - (it_L == begin(X) ? 0 : P[it_L - begin(X) - 1]) << '\n';
        }
    }

    return 0;
}