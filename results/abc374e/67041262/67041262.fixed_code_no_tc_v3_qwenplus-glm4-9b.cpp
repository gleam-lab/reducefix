#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Returns the minimum cost of making the weight W using items A and P or B and Q
ll min_cost(ll W, ll A, ll P, ll B, ll Q) {
    if (P * B < Q * A) {
        // Use more of item A and less of item B
        ll x0 = W / A; // Maximum number of items A we could use
        ll best = LLONG_MAX;
        for (ll dx = 0; dx <= x0; dx++) {
            ll x = x0 - dx;
            ll rem = W - A * x;
            ll y = (rem + B - 1) / B; // Ceiling of rem / B
            best = min(best, P * x + Q * y);
        }
        return best;
    } else {
        // Use more of item B and less of item A
        ll y0 = W / B;
        ll best = LLONG_MAX;
        for (ll dy = 0; dy <= y0; dy++) {
            ll y = y0 - dy;
            ll rem = W - B * y;
            ll x = (rem + A - 1) / A; // Ceiling of rem / A
            best = min(best, P * x + Q * y);
        }
        return best;
    }
}

// Checks if it's possible to make weight W using N items with constraints,
// such that the total cost does not exceed X
bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
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
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 1000000000000LL; // Upper bound is set to a large value
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}