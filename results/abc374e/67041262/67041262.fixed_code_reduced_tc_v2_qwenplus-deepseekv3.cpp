#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Try all possible x in [0, min(W/a, W/b + 1)] to cover near optimal solutions
    ll max_x = min(W / a + 1, (W + b - 1) / b + 1);
    for (ll x = 0; x <= max_x; ++x) {
        ll rem = W - a * x;
        if (rem < 0) rem = 0;
        ll y = (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }
    // Similarly try all possible y in [0, min(W/b, W/a + 1)]
    ll max_y = min(W / b + 1, (W + a - 1) / a + 1);
    for (ll y = 0; y <= max_y; ++y) {
        ll rem = W - b * y;
        if (rem < 0) rem = 0;
        ll x = (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }
    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += min_cost(W, A[i], P[i], B[i], Q[i]);
        if (sum > X) return false;
    }
    return true;
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
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (can(mid, N, X, A, P, B, Q)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";

    return 0;
}