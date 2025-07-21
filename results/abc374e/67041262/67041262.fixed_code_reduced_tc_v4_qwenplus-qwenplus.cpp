#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Returns the minimum cost to achieve at least W units of weight
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Ensure no division by zero
    if (a == 0 && b == 0) return 0;  // Edge case: cannot contribute anything
    if (a == 0) return q * ((W + b - 1) / b);
    if (b == 0) return p * ((W + a - 1) / a);

    // Try both strategies: favoring S or T
    ll best = LLONG_MAX;

    // Strategy 1: Favor using x (S)
    ll x0 = (W + a - 1) / a;  // Ceiling for full coverage
    for (ll dx = 0; dx <= b && x0 - dx >= 0; dx++) {
        ll x = x0 - dx;
        ll rem = max(0LL, W - a * x);
        ll y = (rem == 0 ? 0 : (rem + b - 1) / b);
        best = min(best, p * x + q * y);
    }

    // Strategy 2: Favor using y (T)
    ll y0 = (W + b - 1) / b;
    for (ll dy = 0; dy <= a && y0 - dy >= 0; dy++) {
        ll y = y0 - dy;
        ll rem = max(0LL, W - b * y);
        ll x = (rem == 0 ? 0 : (rem + a - 1) / a);
        best = min(best, p * x + q * y);
    }

    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        total_cost += c;
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

    ll lo = 0, hi = 1000000000000LL; // Upper bound sufficiently large
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}