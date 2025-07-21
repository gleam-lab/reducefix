#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;

    if (p * b < q * a) {
        // Prefer using S (a per unit, cost p)
        ll x0 = W / a;
        for (ll dx = 0; dx <= b + 1 && x0 - dx >= 0; dx++) {
            ll x = x0 - dx;
            ll rem = W - a * x;
            ll y = rem <= 0 ? 0 : (rem + b - 1) / b;
            best = min(best, p * x + q * y);
        }
    } else {
        // Prefer using T (b per unit, cost q)
        ll y0 = W / b;
        for (ll dy = 0; dy <= a + 1 && y0 - dy >= 0; dy++) {
            ll y = y0 - dy;
            ll rem = W - b * y;
            ll x = rem <= 0 ? 0 : (rem + a - 1) / a;
            best = min(best, p * x + q * y);
        }
    }

    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        total += c;
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
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 20000000000LL; // Increased safety margin
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }

    cout << lo << "\n";
    return 0;
}