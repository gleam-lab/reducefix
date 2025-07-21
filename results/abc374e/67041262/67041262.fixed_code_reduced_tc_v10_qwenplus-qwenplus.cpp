#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate minimum cost to achieve at least W weight using two item types
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Ensure we don't do unnecessary work; make sure a and b are positive
    if (W == 0) return 0;
    
    // Try both strategies: favoring item A or favoring item B
    ll best = LLONG_MAX;

    // Strategy 1: Use as many of item A as possible
    ll x_max = min(W / a + 1, (ll)2e5);  // Upper bound for search range
    for (ll x = max(0LL, x_max - 200); x <= x_max && x >= 0; ++x) {
        ll remaining = max(0LL, W - a * x);
        ll y = (remaining + b - 1) / b;
        best = min(best, x * p + y * q);
    }

    // Strategy 2: Use as many of item B as possible
    ll y_max = min(W / b + 1, (ll)2e5);
    for (ll y = max(0LL, y_max - 200); y <= y_max && y >= 0; ++y) {
        ll remaining = max(0LL, W - b * y);
        ll x = (remaining + a - 1) / a;
        best = min(best, x * p + y * q);
    }

    return best;
}

// Check if we can buy enough food for all cats within budget X
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

    // Binary search on maximum possible weight
    ll lo = 0, hi = 1e18; // Wide enough range
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}