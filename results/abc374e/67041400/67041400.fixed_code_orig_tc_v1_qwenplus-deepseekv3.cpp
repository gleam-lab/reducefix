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

        // Determine the maximum possible x (only S)
        ll max_x = (W + A[i] - 1) / A[i];
        // The maximum possible y (only T)
        ll max_y = (W + B[i] - 1) / B[i];

        // We need to find x such that x >= 0, y >= 0, and A[i] * x + B[i] * y >= W
        // The cost is P[i] * x + Q[i] * y
        // The optimal x can be found by considering the derivative or by checking discrete points

        // The optimal x (continuous) would be where the marginal cost per work is minimized
        // The continuous optimal x is W * Q[i] / (A[i] * Q[i] + B[i] * P[i])
        // We check around this x (floor and ceil) and also the boundary values

        vector<ll> x_candidates;
        x_candidates.push_back(0);
        x_candidates.push_back(max_x);
        if (max_y > 0) {
            x_candidates.push_back(max(0LL, W / A[i]));
            x_candidates.push_back(min(max_x, (W + A[i] - 1) / A[i] - 1));
        }

        // Continuous optimal x
        if (A[i] * Q[i] + B[i] * P[i] != 0) {
            ll x_star = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
            for (ll x = max(0LL, x_star - 2); x <= min(max_x, x_star + 2); ++x) {
                x_candidates.push_back(x);
            }
        }

        // Remove duplicates
        sort(x_candidates.begin(), x_candidates.end());
        x_candidates.erase(unique(x_candidates.begin(), x_candidates.end()), x_candidates.end());

        for (ll x : x_candidates) {
            if (x < 0 || x > max_x) continue;
            ll remaining = W - A[i] * x;
            ll y = remaining <= 0 ? 0 : (remaining + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best) best = cost;
        }

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

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        ll max_A = (X / P[i]) * A[i];
        ll max_B = (X / Q[i]) * B[i];
        hi = max(hi, max(max_A, max_B));
    }
    hi += 1; // To ensure the upper bound is inclusive

    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}