#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to get at least W units of a resource,
// using two types of packages:
// - Type S: gives 'a' units at cost 'p'
// - Type T: gives 'b' units at cost 'q'
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Try both strategies: favoring S and favoring T
    ll best = LLONG_MAX;

    // Strategy 1: Use more of type S (try up to b number of S)
    if (W > 0) {
        ll max_s = min(W / a + 1, (ll)2e6); // Prevent overflow with reasonable limit
        for (ll x = max(0LL, max_s - 200); x <= max_s; x++) {
            ll rem = max(0LL, W - a * x);
            ll y = (rem + b - 1) / b;
            best = min(best, p * x + q * y);
        }
    } else {
        best = 0;
    }

    // Strategy 2: Use more of type T (try up to a number of T)
    if (W > 0) {
        ll max_t = min(W / b + 1, (ll)2e6);
        for (ll y = max(0LL, max_t - 200); y <= max_t; y++) {
            ll rem = max(0LL, W - b * y);
            ll x = (rem + a - 1) / a;
            best = min(best, p * x + q * y);
        }
    } else {
        best = min(best, (ll)0);
    }

    return best;
}

// Checks if we can buy at least W units from all N vendors with total cost ≤ X
bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
    }
    return sum <= X;
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

    // Binary search on maximum possible W that can be bought within budget X
    ll lo = 0, hi = 1000000000000LL; // Upper bound is large enough
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}