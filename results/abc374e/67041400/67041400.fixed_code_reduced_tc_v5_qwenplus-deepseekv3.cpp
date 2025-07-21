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

        // Calculate the minimal cost for this stage to produce at least W
        // We need to find x and y such that A[i]*x + B[i]*y >= W with minimal P[i]*x + Q[i]*y
        // The optimal x is around W*Q[i]/(A[i]*Q[i] + B[i]*P[i])
        // We'll check candidates around this value
        
        // Handle the case where W is 0 (shouldn't happen in binary search)
        if (W == 0) {
            best = 0;
            total += best;
            continue;
        }

        // Calculate all possible x candidates
        vector<ll> x_candidates;
        
        // x = 0 (all y)
        x_candidates.push_back(0);
        
        // x = ceil(W / A[i]) (all x)
        ll max_x = (W + A[i] - 1) / A[i];
        x_candidates.push_back(max_x);
        
        // Optimal x from continuous relaxation
        if (A[i] * Q[i] + B[i] * P[i] != 0) {
            long double x_star = (long double)W * Q[i] / (A[i] * Q[i] + B[i] * P[i]);
            ll x_floor = floor(x_star);
            ll x_ceil = ceil(x_star);
            
            x_candidates.push_back(x_floor);
            x_candidates.push_back(x_ceil);
            x_candidates.push_back(max(x_floor - 1, 0LL));
            x_candidates.push_back(min(x_ceil + 1, max_x));
        }

        // Remove duplicates and sort
        sort(x_candidates.begin(), x_candidates.end());
        x_candidates.erase(unique(x_candidates.begin(), x_candidates.end()), x_candidates.end());

        // Evaluate all x candidates
        for (ll x : x_candidates) {
            if (x < 0 || x > max_x) continue;
            
            ll remaining = W - A[i] * x;
            ll y = remaining <= 0 ? 0 : (remaining + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            
            if (cost < best) {
                best = cost;
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
        hi = max(hi, max(A[i], B[i]) * (X / min(P[i], Q[i]) + 1));
    }

    // Binary search to find the maximum W
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