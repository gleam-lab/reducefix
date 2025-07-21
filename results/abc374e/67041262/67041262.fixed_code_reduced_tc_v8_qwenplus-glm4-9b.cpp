#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Helper function to determine the minimum cost of building a wall of width W using materials A[i], B[i], with prices P[i], Q[i]
ll min_cost(ll W, ll A, ll P, ll B, ll Q) {
    // We need to maximize the utilization of the less expensive material
    if (P < Q) {
        // Use more of the cheaper material A if possible
        ll x0 = W / A;
        for (ll dx = 0; dx <= B && x0 >= dx; dx++) {
            ll x = x0 - dx;
            ll rem = W - A * x;
            ll y = rem <= 0 ? 0 : (rem + B - 1) / B;
            if (y == 0) break; // Since x was minimized, y will also be minimized, no need to continue if y is 0
            ll cost = P * x + Q * y;
            if (cost < LLONG_MAX) return cost;
        }
    } else {
        // Use more of the cheaper material B if possible
        ll y0 = W / B;
        for (ll dy = 0; dy <= A && y0 >= dy; dy++) {
            ll y = y0 - dy;
            ll rem = W - B * y;
            ll x = rem <= 0 ? 0 : (rem + A - 1) / A;
            if (x == 0) break; // Since y was minimized, x will also be minimized, no need to continue if x is 0
            ll cost = P * x + Q * y;
            if (cost < LLONG_MAX) return cost;
        }
    }
    return LLONG_MAX; // This should never be reached if the input is valid
}

// Function to determine if a given budget X can cover the construction of N walls
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

    ll lo = 0, hi = 1000000000000LL; // Upper limit is set very high
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}