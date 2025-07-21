#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    
    // Try all possible x in [0, W/a + 1] that could potentially be optimal
    // Similarly for y, but we can limit the search to a reasonable range
    // around the optimal ratio to find the minimum cost
    
    // Case 1: Use only x
    ll x = (W + a - 1) / a;
    best = min(best, x * p);
    
    // Case 2: Use only y
    ll y = (W + b - 1) / b;
    best = min(best, y * q);
    
    // Case 3: Use combination of x and y
    // We'll check around the optimal ratio to find the minimum
    for (ll x = 0; x <= W/a + 1; ++x) {
        ll remaining = W - a * x;
        if (remaining <= 0) {
            best = min(best, x * p);
            continue;
        }
        ll y = (remaining + b - 1) / b;
        best = min(best, x * p + y * q);
    }
    
    // Also check combinations around the other optimal ratio
    for (ll y = 0; y <= W/b + 1; ++y) {
        ll remaining = W - b * y;
        if (remaining <= 0) {
            best = min(best, y * q);
            continue;
        }
        ll x = (remaining + a - 1) / a;
        best = min(best, x * p + y * q);
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

    ll lo = 0, hi = 1e18;
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