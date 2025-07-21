#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Computes the minimum cost to achieve at least W units of weight using two types of items
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Strategy: Try both strategies - prioritizing item S (a per unit) and T (b per unit)
    ll best = LLONG_MAX;

    // Ensure that we try both approaches: x-heavy and y-heavy
    auto update_best = [&](ll x, ll y) {
        if (x >= 0 && y >= 0)
            best = min(best, x * p + y * q);
    };

    // Heuristic: try both directions: x heavy and y heavy
    vector<tuple<ll, ll, ll, ll, ll>> strategies = {
        {a, p, b, q, 0},  // original
        {b, q, a, p, 1}   // swapped
    };

    for (auto [s_a, s_p, s_b, s_q, swapped] : strategies) {
        ll max_x = (W + s_a - 1) / s_a; // ceil division
        for (ll x = max_x; x >= max(0LL, max_x - 20); x--) {
            ll rem = max(0LL, W - x * s_a);
            ll y = (rem + s_b - 1) / s_b;
            if (swapped == 0) update_best(x, y);
            else update_best(y, x);
        }

        ll x0 = W / s_a;
        for (ll dx = 0; dx <= 20 && x0 - dx >= 0; dx++) {
            ll x = x0 - dx;
            ll rem = max(0LL, W - x * s_a);
            ll y = (rem + s_b - 1) / s_b;
            if (swapped == 0) update_best(x, y);
            else update_best(y, x);
        }

        for (ll dy = 0; dy <= 20 && x0 - dy >= 0; dy++) {
            ll y = dy;
            ll rem = max(0LL, W - y * s_b);
            ll x = (rem + s_a - 1) / s_a;
            if (swapped == 0) update_best(x, y);
            else update_best(y, x);
        }
    }

    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll cost = min_cost(W, A[i], P[i], B[i], Q[i]);
        total_cost += cost;
        if (total_cost > X) return false;
    }
    return total_cost <= X;
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

    ll lo = 0, hi = 1e18; // Binary search bounds

    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}