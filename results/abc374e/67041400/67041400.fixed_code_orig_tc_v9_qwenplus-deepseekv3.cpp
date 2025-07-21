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

        // The optimal x can be derived by minimizing P[i]*x + Q[i]*y under the constraint A[i]*x + B[i]*y >= W
        // We can solve for x in terms of y or vice versa. Here, we consider x from 0 to the maximum possible x needed.
        ll max_x = (W + A[i] - 1) / A[i];
        ll min_x = 0;

        // The optimal x is likely around the point where the marginal cost per unit of W is minimized.
        // We can consider x in the vicinity of this point.
        // The optimal x_star can be derived as (W * Q[i]) / (A[i]*Q[i] + B[i]*P[i])
        // We then check around this point for the minimal cost.
        long double x_star = (long double)W * Q[i] / ((long double)A[i] * Q[i] + (long double)B[i] * P[i]);
        ll x_start = max(min_x, min(max_x, (ll)floor(x_star) - 2));
        ll x_end = min(max_x, (ll)ceil(x_star) + 2);

        for(ll x = x_start; x <= x_end; x++){
            ll rem = W - A[i] * x;
            ll y = (rem <= 0) ? 0 : (rem + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if(cost < best) best = cost;
        }

        // Also check the boundary cases where x = 0 or x = max_x
        ll x = 0;
        ll rem = W - A[i] * x;
        ll y = (rem <= 0) ? 0 : (rem + B[i] - 1) / B[i];
        ll cost = P[i] * x + Q[i] * y;
        if(cost < best) best = cost;

        x = max_x;
        rem = W - A[i] * x;
        y = (rem <= 0) ? 0 : (rem + B[i] - 1) / B[i];
        cost = P[i] * x + Q[i] * y;
        if(cost < best) best = cost;

        total += best;
        if(total > X) return X + 1;
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
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi += 1;

    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo - 1 << "\n";
    return 0;
}