#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to cover weight W using two types of items
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // We try both strategies: prioritizing item S (a per unit), and item T (b per unit)
    ll best = LLONG_MAX;

    // Strategy 1: Try using more of item S and supplement with T
    if (W > 0) {
        ll max_x = (W + a - 1) / a;  // ceiling division for full coverage
        for (ll x = 0; x <= max_x && x <= 1000000; ++x) {
            ll rem = max(0LL, W - a * x);
            ll y = (rem + b - 1) / b; // ceil division
            best = min(best, x * p + y * q);
        }
    } else {
        best = 0; // No weight needed
    }

    // Strategy 2: Try using more of item T and supplement with S
    if (W > 0) {
        ll max_y = (W + b - 1) / b;  // ceiling division for full coverage
        for (ll y = 0; y <= max_y && y <= 1000000; ++y) {
            ll rem = max(0LL, W - b * y);
            ll x = (rem + a - 1) / a; // ceil division
            best = min(best, x * p + y * q);
        }
    }

    return best;
}

// Checks if we can build a string of total weight W with budget X
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

    ll lo = 0, hi = 1e18; // Large upper bound to ensure coverage
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}