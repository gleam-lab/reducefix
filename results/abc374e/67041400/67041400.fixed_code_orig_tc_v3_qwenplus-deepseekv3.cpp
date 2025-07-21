#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve W, returning X+1 if it exceeds X
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];
        
        // Function to calculate the cost for a given x
        auto calculate_cost = [&](ll x) {
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };

        // Check x = 0 (all y)
        best = min(best, calculate_cost(0));
        if (best == 0) {
            total += best;
            continue;
        }

        // Check x = max_x (all x)
        best = min(best, calculate_cost(max_x));
        
        // Find the optimal x where the cost might be minimized
        // The optimal x is where the derivative of the cost function is zero
        // The cost is P[i]*x + Q[i]*ceil((W - A[i]*x)/B[i])
        // To find the minimal cost, we can consider the continuous case and then check nearby integers
        ll x_opt = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
        for (ll x = max(0LL, x_opt - 2); x <= min(max_x, x_opt + 2); ++x) {
            best = min(best, calculate_cost(x));
        }

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

    // Binary search to find the maximum W
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