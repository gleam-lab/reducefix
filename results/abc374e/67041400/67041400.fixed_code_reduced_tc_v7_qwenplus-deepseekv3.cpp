#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;

        // Calculate the minimal cost for process i to achieve at least W
        ll max_x = (W + A[i] - 1) / A[i];
        ll max_y = (W + B[i] - 1) / B[i];

        // We need to find x and y such that A[i]*x + B[i]*y >= W
        // and P[i]*x + Q[i]*y is minimized
        // The optimal x is around (W * Q[i]) / (A[i]*Q[i] + B[i]*P[i])
        // We consider x around this value and also the boundaries

        vector<ll> xs;
        ll x_opt = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
        for (ll x = max(0LL, x_opt - 2); x <= min(max_x, x_opt + 2); ++x) {
            ll remaining = W - A[i] * x;
            ll y = remaining <= 0 ? 0 : (remaining + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best) best = cost;
        }

        // Also check the all y case (x = 0)
        ll y_all = max_y;
        ll cost_all_y = Q[i] * y_all;
        if (cost_all_y < best) best = cost_all_y;

        total += best;
        if (total > X) return X + 1;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    if (X == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Binary search boundaries
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max(A[i], B[i]) * (X / min(P[i], Q[i]) + 1);
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