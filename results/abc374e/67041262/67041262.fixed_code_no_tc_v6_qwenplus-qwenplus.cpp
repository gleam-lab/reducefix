#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to achieve at least W units of weight using two item types
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Try both strategies: use more of item S (a, p) or item T (b, q)
    ll best = LLONG_MAX;

    // Strategy 1: Use as much of S as possible, then fill with T
    ll x0 = W / a;
    for (ll dx = 0; dx <= b && x0 >= dx; dx++) {
        ll x = max(0LL, x0 - dx); // Ensure x is not negative
        ll rem = max(0LL, W - a * x);
        ll y = (rem + b - 1) / b; // ceil division
        best = min(best, p * x + q * y);
    }

    // Strategy 2: Use as much of T as possible, then fill with S
    ll y0 = W / b;
    for (ll dy = 0; dy <= a && y0 >= dy; dy++) {
        ll y = max(0LL, y0 - dy); // Ensure y is not negative
        ll rem = max(0LL, W - b * y);
        ll x = (rem + a - 1) / a; // ceil division
        best = min(best, p * x + q * y);
    }

    return best;
}

// Checks if we can make all dishes within total cost X
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

    ll lo = 0, hi = 1e14; // Increased upper bound for safety
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}