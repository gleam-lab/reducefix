#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        ll best_cost = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];
        ll x_star = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
        
        for (ll x = max(0LL, x_star - 2); x <= min(max_x, x_star + 2); ++x) {
            ll rem = W - A[i] * x;
            ll y = (rem <= 0) ? 0 : (rem + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best_cost) {
                best_cost = cost;
            }
        }
        
        total += best_cost;
        if (total > X) {
            return X + 1;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0;
    ll hi = 0;
    for (int i = 0; i < N; ++i) {
        ll max_contribution = max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
        hi += max_contribution;
    }
    hi += 1;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo - 1 << "\n";
    return 0;
}