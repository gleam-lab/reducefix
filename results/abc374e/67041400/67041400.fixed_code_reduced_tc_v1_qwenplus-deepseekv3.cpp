#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        if(W == 0) continue;  // No need to spend anything
        
        ll best = X + 1;
        
        // The maximum x we might need (when y is 0)
        ll max_x = (W + A[i] - 1) / A[i];
        
        // Function to calculate cost for a given x
        auto calculate_cost = [&](ll x) {
            if(x < 0) return LLONG_MAX;
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };
        
        // Check boundary cases
        best = min(best, calculate_cost(0));  // All y
        best = min(best, calculate_cost(max_x));  // All x
        
        // Check the optimal point if it exists
        if(A[i] * Q[i] - B[i] * P[i] != 0) {
            ll x_star = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
            for(ll x = max(0LL, x_star - 2); x <= x_star + 2; x++) {
                if(x <= max_x) {
                    best = min(best, calculate_cost(x));
                }
            }
        }
        
        total += best;
        if(total > X) return X+1;
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

    // Handle X = 0 case separately
    if(X == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi = max(hi, max((X / P[i] + 1) * A[i], (X / Q[i] + 1) * B[i]));
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