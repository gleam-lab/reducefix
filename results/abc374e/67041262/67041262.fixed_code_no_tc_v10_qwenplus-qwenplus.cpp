#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to obtain at least W units of the ingredient
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Try both strategies: using more of a or more of b
    ll best = LLONG_MAX;

    // Strategy 1: Use as much of a as possible
    ll x_max = (W + a - 1) / a;  // ceil division
    for (ll x = max(0LL, x_max - b); x <= x_max; x++) {
        if (x < 0) continue;
        ll rem = max(0LL, W - a * x);
        ll y = (rem + b - 1) / b;  // ceil division
        best = min(best, p * x + q * y);
    }

    // Strategy 2: Use as much of b as possible
    ll y_max = (W + b - 1) / b;  // ceil division
    for (ll y = max(0LL, y_max - a); y <= y_max; y++) {
        if (y < 0) continue;
        ll rem = max(0LL, W - b * y);
        ll x = (rem + a - 1) / a;  // ceil division
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

    ll lo = 0, hi = 1e18; // Using larger hi for safety
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";

    return 0;
}