#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to achieve at least W units of nutrient
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // We try both strategies: using mostly S (a units per p cost), or T (b units per q cost)
    ll best = LLONG_MAX;

    // Strategy 1: Try using more of S (x), and supplement with T (y)
    ll x0 = (W + a - 1) / a;  // ceil division
    for (ll dx = 0; dx <= b; dx++) {
        ll x = x0 - dx;
        if (x < 0) continue;
        ll rem = max(0LL, W - a * x);
        ll y = (rem + b - 1) / b;  // ceil division
        best = min(best, x * p + y * q);
    }

    // Strategy 2: Try using more of T (y), and supplement with S (x)
    ll y0 = (W + b - 1) / b;  // ceil division
    for (ll dy = 0; dy <= a; dy++) {
        ll y = y0 - dy;
        if (y < 0) continue;
        ll rem = max(0LL, W - b * y);
        ll x = (rem + a - 1) / a;  // ceil division
        best = min(best, x * p + y * q);
    }

    return best;
}

// Checks if we can make all dishes with maximum weight `W` under total cost `X`
bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        total_cost += c;
        if (total_cost > X) return false;
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

    // Binary search on the answer (maximum weight per dish)
    ll lo = 0, hi = 1e18; // Use a safe high upper bound
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}