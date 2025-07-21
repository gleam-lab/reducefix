#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;

    // Try x near floor(W / a)
    ll x0 = W / a;
    for (ll dx = -100; dx <= 100; dx++) {
        ll x = max(0LL, x0 + dx);
        ll rem = W - a * x;
        if (rem <= 0) {
            best = min(best, p * x);
        } else {
            ll y = (rem + b - 1) / b;
            best = min(best, p * x + q * y);
        }
    }

    // Try y near floor(W / b)
    ll y0 = W / b;
    for (ll dy = -100; dy <= 100; dy++) {
        ll y = max(0LL, y0 + dy);
        ll rem = W - b * y;
        if (rem <= 0) {
            best = min(best, q * y);
        } else {
            ll x = (rem + a - 1) / a;
            best = min(best, p * x + q * y);
        }
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

    ll lo = 0, hi = 1'000'000'000'000LL; // Upper bound sufficiently large
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";

    return 0;
}