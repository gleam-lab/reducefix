#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // We need to explore more possibilities around the optimal point
    ll max_x = min(W / a + 2, (W + a - 1) / a);
    ll max_y = min(W / b + 2, (W + b - 1) / b);
    
    // Check both strategies since the initial efficiency comparison might not always be perfect
    // Strategy 1: prioritize type S
    for (ll x = max(0LL, W/a - 100); x <= max_x; x++) {
        ll rem = W - a * x;
        if (rem < 0) rem = 0;
        ll y = (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }
    
    // Strategy 2: prioritize type T
    for (ll y = max(0LL, W/b - 100); y <= max_y; y++) {
        ll rem = W - b * y;
        if (rem < 0) rem = 0;
        ll x = (rem + a - 1) / a;
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

    ll lo = 0, hi = 1LL << 60; // Larger upper bound
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