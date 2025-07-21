#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        ll best_cost = X + 1;

        // The optimal x is derived from minimizing the cost to achieve W
        ll max_x = (W + A[i] - 1) / A[i];
        ll x_star = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
        
        // Check around x_star to find the minimal cost
        for (ll x = max(0LL, x_star - 2); x <= min(max_x, x_star + 2); ++x) {
            ll rem = W - A[i] * x;
            ll y = max(0LL, rem <= 0 ? 0 : (rem + B[i] - 1) / B[i]);
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best_cost) {
                best_cost = cost;
            }
        }

        // Also check the all T case (x = 0)
        ll y_all_T = (W + B[i] - 1) / B[i];
        ll cost_all_T = Q[i] * y_all_T;
        if (cost_all_T < best_cost) {
            best_cost = cost_all_T;
        }

        // Also check the all S case (x = max_x)
        ll x_all_S = max_x;
        ll rem_all_S = W - A[i] * x_all_S;
        ll y_all_S = max(0LL, rem_all_S <= 0 ? 0 : (rem_all_S + B[i] - 1) / B[i]);
        ll cost_all_S = P[i] * x_all_S + Q[i] * y_all_S;
        if (cost_all_S < best_cost) {
            best_cost = cost_all_S;
        }

        total += best_cost;
        if (total > X) {
            return X + 1;
        }
    }
    return total;
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

    // Binary search bounds
    ll lo = 0;
    ll hi = 1;
    while (cost_for_W(N, hi, X, A, P, B, Q) <= X) {
        hi *= 2;
    }

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}