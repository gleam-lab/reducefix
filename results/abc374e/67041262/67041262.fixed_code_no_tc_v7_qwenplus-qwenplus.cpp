#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to achieve at least W units of nutrient
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // We try both strategies: using mostly S (a units per p yen), and using mostly T (b units per q yen)
    ll best = LLONG_MAX;

    // Strategy 1: Try using more of S
    ll x_max = min(W / a + 1, (ll)200000); // Cap for practicality
    for (ll x = max(0LL, x_max - 200); x <= x_max && x <= 200000; x++) {
        ll rem = max(0LL, W - a * x);
        ll y = (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }

    // Strategy 2: Try using more of T
    ll y_max = min(W / b + 1, (ll)200000);
    for (ll y = max(0LL, y_max - 200); y <= y_max && y <= 200000; y++) {
        ll rem = max(0LL, W - b * y);
        ll x = (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }

    return best;
}

// Checks if we can satisfy all N cows with total weight at least W
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

    ll lo = 0, hi = 1e18; // Use safe upper bound

    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }

    cout << lo << "\n";
    return 0;
}