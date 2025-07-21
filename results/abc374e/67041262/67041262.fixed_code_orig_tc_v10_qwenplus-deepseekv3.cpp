#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Try both approaches: primarily using S or primarily using T
    // First, try primarily using S
    ll max_x = W / a;
    for (ll x = max(0LL, max_x - 100); x <= max_x + 100; ++x) {
        if (x < 0) continue;
        ll rem = W - a * x;
        if (rem < 0) rem = 0;
        ll y = (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }
    // Then, try primarily using T
    ll max_y = W / b;
    for (ll y = max(0LL, max_y - 100); y <= max_y + 100; ++y) {
        if (y < 0) continue;
        ll rem = W - b * y;
        if (rem < 0) rem = 0;
        ll x = (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }
    return best;
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
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