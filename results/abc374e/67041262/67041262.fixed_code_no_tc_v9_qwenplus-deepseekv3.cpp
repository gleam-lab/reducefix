#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    if (a == 0 && b == 0) return 0; // Both weights are zero, which is impossible as per problem constraints
    if (a == 0) return q * ((W + b - 1) / b); // Only use type T
    if (b == 0) return p * ((W + a - 1) / a); // Only use type S

    ll best = LLONG_MAX;
    // Check all possible x in [max(0, (W - b * k) / a) for some k]
    // To avoid excessive loops, we limit the check to a few candidates around the optimal x and y
    ll x_max = W / a;
    for (ll x = max(0LL, x_max - 2); x <= x_max + 2; ++x) {
        if (x < 0) continue;
        ll rem = W - a * x;
        ll y = (rem <= 0) ? 0 : (rem + b - 1) / b;
        best = min(best, p * x + q * y);
    }
    
    ll y_max = W / b;
    for (ll y = max(0LL, y_max - 2); y <= y_max + 2; ++y) {
        if (y < 0) continue;
        ll rem = W - b * y;
        ll x = (rem <= 0) ? 0 : (rem + a - 1) / a;
        best = min(best, p * x + q * y);
    }
    
    return best;
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
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

    ll lo = 0, hi = 1LL << 60; // Sufficiently large upper bound
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}