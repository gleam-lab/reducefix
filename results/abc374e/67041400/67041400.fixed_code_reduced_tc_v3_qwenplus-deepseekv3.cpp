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
        ll max_x = (W + A[i] - 1) / A[i];
        
        // Check all S machines
        ll x = max_x;
        ll y = 0;
        ll c = P[i] * x + Q[i] * y;
        if(c < best) best = c;
        
        // Check all T machines
        x = 0;
        y = (W + B[i] - 1) / B[i];
        c = P[i] * x + Q[i] * y;
        if(c < best) best = c;
        
        // Check optimal point where we might mix S and T machines
        // We need to find x that minimizes P[i]*x + Q[i]*y where A[i]*x + B[i]*y >= W
        // y = ceil(max(0, W - A[i]*x) / B[i])
        // The optimal x is around (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]), but integers only
        
        // Binary search for optimal x in [0, max_x]
        ll low = 0, high = max_x;
        while(low <= high) {
            ll mid1 = low + (high - low) / 3;
            ll mid2 = high - (high - low) / 3;
            
            ll y1 = max(0LL, W - A[i] * mid1 + B[i] - 1) / B[i];
            ll c1 = P[i] * mid1 + Q[i] * y1;
            
            ll y2 = max(0LL, W - A[i] * mid2 + B[i] - 1) / B[i];
            ll c2 = P[i] * mid2 + Q[i] * y2;
            
            if(c1 < best) best = c1;
            if(c2 < best) best = c2;
            
            if(c1 < c2) {
                high = mid2 - 1;
            } else {
                low = mid1 + 1;
            }
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

    // Compute maximum possible W
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi += 1; // To cover the case when X is very large

    // Binary search to find maximum W
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