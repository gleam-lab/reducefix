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
        
        // Candidate x values:
        // 1. x = 0 (all Ti)
        // 2. x = ceil(W/A[i]) (all Si)
        // 3. Optimal x from continuous relaxation
        // 4. Nearby points to optimal x
        vector<ll> xs;
        
        // All Ti
        xs.push_back(0);
        
        // All Si
        ll all_S = (W + A[i] - 1) / A[i];
        xs.push_back(all_S);
        
        // Optimal x from continuous relaxation
        if (A[i] > 0 && B[i] > 0) {
            long double x_star = (long double)W * Q[i] * A[i] / ((long double)A[i]*A[i]*Q[i] + (long double)B[i]*B[i]*P[i]);
            ll x_opt = max(0LL, min(all_S, (ll)round(x_star)));
            
            // Add nearby points
            for (ll dx = -2; dx <= 2; dx++) {
                ll x = x_opt + dx;
                if (x >= 0 && x <= all_S) {
                    xs.push_back(x);
                }
            }
        }
        
        // Remove duplicates
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        // Evaluate all candidates
        for(ll x : xs) {
            ll rem = W - A[i] * x;
            ll y = max(0LL, (rem + B[i] - 1) / B[i]);
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best) best = cost;
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

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi = min(hi, (ll)1e18);
    
    // Binary search [lo, hi]
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