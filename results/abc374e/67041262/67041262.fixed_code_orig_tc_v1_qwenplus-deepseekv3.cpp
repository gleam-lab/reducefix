#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Determine which item is more cost-effective per unit weight
    if (p * b <= q * a) {
        // Item A is more cost-effective, use as much as possible
        ll max_x = W / a;
        // Check around max_x to find the optimal x
        for (ll x = max(max_x - b, 0LL); x <= max_x + b && x >= 0; ++x) {
            ll remaining = W - a * x;
            if (remaining <= 0) {
                best = min(best, p * x);
                continue;
            }
            ll y = (remaining + b - 1) / b; // ceil(remaining / b)
            best = min(best, p * x + q * y);
        }
    } else {
        // Item B is more cost-effective, use as much as possible
        ll max_y = W / b;
        // Check around max_y to find the optimal y
        for (ll y = max(max_y - a, 0LL); y <= max_y + a && y >= 0; ++y) {
            ll remaining = W - b * y;
            if (remaining <= 0) {
                best = min(best, q * y);
                continue;
            }
            ll x = (remaining + a - 1) / a; // ceil(remaining / a)
            best = min(best, p * x + q * y);
        }
    }
    return best;
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) {
            return false;
        }
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