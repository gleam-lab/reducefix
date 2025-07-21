#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Try all possible x in [0, ceil(W/a)]
    ll max_x = (W + a - 1) / a;
    for (ll x = 0; x <= max_x; x++) {
        ll remaining = W - a * x;
        if (remaining < 0) remaining = 0;
        ll y = (remaining + b - 1) / b;
        best = min(best, p * x + q * y);
    }
    // Also try all possible y in [0, ceil(W/b)]
    ll max_y = (W + b - 1) / b;
    for (ll y = 0; y <= max_y; y++) {
        ll remaining = W - b * y;
        if (remaining < 0) remaining = 0;
        ll x = (remaining + a - 1) / a;
        best = min(best, p * x + q * y);
    }
    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
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
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 0;
    // First find a suitable upper bound
    while (true) {
        if (can(hi, N, X, A, P, B, Q)) {
            if (hi == 0) hi = 1;
            else hi *= 2;
        } else {
            break;
        }
    }

    // Binary search between lo and hi
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