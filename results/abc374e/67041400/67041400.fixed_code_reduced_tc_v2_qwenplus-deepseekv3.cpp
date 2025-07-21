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

        // Calculate the minimal cost for this process to achieve W
        // Try all possible x values that could be optimal
        ll max_x = (W + A[i] - 1) / A[i];
        // The optimal x is either 0, max_x, or somewhere in between
        // We can use ternary search to find the minimal cost
        ll left = 0, right = max_x;
        while (left <= right) {
            ll mid1 = left + (right - left) / 3;
            ll mid2 = right - (right - left) / 3;
            
            ll rem1 = W - A[i] * mid1;
            ll y1 = rem1 <= 0 ? 0 : (rem1 + B[i] - 1) / B[i];
            ll cost1 = P[i] * mid1 + Q[i] * y1;
            
            ll rem2 = W - A[i] * mid2;
            ll y2 = rem2 <= 0 ? 0 : (rem2 + B[i] - 1) / B[i];
            ll cost2 = P[i] * mid2 + Q[i] * y2;
            
            best = min({best, cost1, cost2});
            
            if (cost1 < cost2) {
                right = mid2 - 1;
            } else {
                left = mid1 + 1;
            }
        }
        
        // Also check the boundaries
        for (ll x : {0LL, max_x}) {
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            best = min(best, cost);
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

    // Binary search between 0 and maximum possible W
    ll lo = 0, hi = 0;
    if (X > 0) {
        long double best_ratio = 0;
        for(int i = 0; i < N; i++){
            best_ratio = max(best_ratio, (long double)A[i] / P[i]);
            best_ratio = max(best_ratio, (long double)B[i] / Q[i]);
        }
        hi = (ll)floor(X * best_ratio) + 1;
    }

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