#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Ensure we try both directions: using more of a or more of b
    ll best = LLONG_MAX;

    // Try using mostly a
    ll x0 = (W + a - 1) / a;  // ceil division to ensure coverage
    for (ll dx = 0; dx <= b; dx++) {
        ll x = x0 - dx;
        if (x < 0) break;
        ll rem = W - a * x;
        ll y = (rem <= 0) ? 0 : (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }

    // Try using mostly b
    ll y0 = (W + b - 1) / b;
    for (ll dy = 0; dy <= a; dy++) {
        ll y = y0 - dy;
        if (y < 0) break;
        ll rem = W - b * y;
        ll x = (rem <= 0) ? 0 : (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }

    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll cost = min_cost(W, A[i], P[i], B[i], Q[i]);
        total_cost += cost;
        if (total_cost > X) return false;
    }
    return total_cost <= X;
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

    ll lo = 0, hi = 1e18;
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
    return 0;
}