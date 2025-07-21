#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate minimum cost to obtain at least W units using two item types
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Ensure we don't divide by zero
    if (a == 0 && b == 0) return 0;
    if (a == 0) return q * ((W + b - 1) / b);
    if (b == 0) return p * ((W + a - 1) / a);

    // Try both strategies: favoring type S or type T
    ll best = LLONG_MAX;

    // Strategy 1: Favor item type S
    ll x0 = (W + a - 1) / a;  // Ceiling division
    for (ll dx = 0; dx <= b && x0 >= dx; dx++) {
        ll x = x0 - dx;
        ll rem = max(0LL, W - a * x);
        ll y = (rem == 0) ? 0 : (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }

    // Strategy 2: Favor item type T
    ll y0 = (W + b - 1) / b;  // Ceiling division
    for (ll dy = 0; dy <= a && y0 >= dy; dy++) {
        ll y = y0 - dy;
        ll rem = max(0LL, W - b * y);
        ll x = (rem == 0) ? 0 : (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }

    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; i++) {
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
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search over the possible answer
    ll lo = 0, hi = 1e18;  // Start with a large enough upper bound
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;  // Use +1 to avoid infinite loops
        if (can(mid, N, X, A, P, B, Q))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}