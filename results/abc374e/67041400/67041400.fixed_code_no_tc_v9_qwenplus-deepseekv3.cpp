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
        
        // Function to calculate cost for given x
        auto get_cost = [&](ll x) {
            if(x < 0) return LLONG_MAX;
            ll rem = W - A[i] * x;
            ll y = max(0LL, rem <= 0 ? 0 : (rem + B[i] - 1) / B[i]);
            return P[i] * x + Q[i] * y;
        };

        // Check boundary cases
        best = min(best, get_cost(0));  // All Ti
        best = min(best, get_cost((W + A[i] - 1) / A[i]));  // All Si
        
        // Find optimal x for continuous case if B[i] > 0
        if(B[i] > 0) {
            ll x_star_num = W * Q[i];
            ll x_star_den = A[i] * Q[i] + B[i] * P[i];
            if(x_star_den > 0) {
                ll x_star = x_star_num / x_star_den;
                // Check nearby points
                for(ll x = max(0LL, x_star - 2); x <= x_star + 2; x++) {
                    best = min(best, get_cost(x));
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

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi = max(hi, 1LL) + 1;

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