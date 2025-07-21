#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Calculate the minimal cost to cover at least W units
    // First determine which combination of x and y gives the minimal cost
    ll best = LLONG_MAX;
    
    // Try both strategies: prioritize a or b based on efficiency
    // Strategy 1: use as much a as possible
    ll x = W / a;
    for (ll dx = 0; dx <= 2; dx++) {
        ll curr_x = max(0LL, x - dx);
        ll rem = W - a * curr_x;
        ll y = (rem <= 0) ? 0 : (rem + b - 1) / b;
        best = min(best, curr_x * p + y * q);
    }
    
    // Strategy 2: use as much b as possible
    ll y = W / b;
    for (ll dy = 0; dy <= 2; dy++) {
        ll curr_y = max(0LL, y - dy);
        ll rem = W - b * curr_y;
        ll x = (rem <= 0) ? 0 : (rem + a - 1) / a;
        best = min(best, x * p + curr_y * q);
    }
    
    return best;
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll total = 0;
    for (int i = 0; i < N; i++) {
        total += min_cost(W, A[i], P[i], B[i], Q[i]);
        if (total > X) return false;
    }
    return total <= X;
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