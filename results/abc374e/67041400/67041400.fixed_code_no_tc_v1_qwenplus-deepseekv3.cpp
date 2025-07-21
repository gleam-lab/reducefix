#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate minimal cost to achieve W for each process
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;
        
        // Critical points to check:
        // 1. x = 0 (all T)
        // 2. x = ceil(W/A[i]) (all S)
        // 3. Points where the cost function might have minima
        // We need to check the integer points around the theoretical minimum
        
        // Calculate all S case
        ll all_S = (W + A[i] - 1) / A[i];
        best = min(best, P[i] * all_S);
        
        // Calculate all T case
        ll all_T = (W + B[i] - 1) / B[i];
        best = min(best, Q[i] * all_T);
        
        // Calculate the optimal mixed case
        // The optimal x (number of S) is in [0, all_S]
        // We can find it by checking the point where the derivative would be zero
        if (A[i] > 0 && B[i] > 0) {
            ll x = (W * Q[i] * B[i]) / (P[i] * B[i] + Q[i] * A[i]);
            // Check x and nearby points for optimal solution
            for (ll dx = -2; dx <= 2; dx++) {
                ll test_x = x + dx;
                if (test_x < 0 || test_x > all_S) continue;
                ll rem = W - A[i] * test_x;
                if (rem < 0) rem = 0;
                ll y = (rem + B[i] - 1) / B[i];
                best = min(best, P[i] * test_x + Q[i] * y);
            }
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
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi += 1;  // To ensure we cover the maximum possible

    // Binary search to find maximum W
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(mid == lo) mid = hi;  // Prevent infinite loop when lo+1 == hi
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}