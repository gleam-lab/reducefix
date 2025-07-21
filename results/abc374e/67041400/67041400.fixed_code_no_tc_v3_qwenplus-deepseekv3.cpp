#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate minimum cost to achieve W, return X+1 if impossible
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;

        // Calculate max possible x (all S)
        ll max_x = (W + A[i] - 1) / A[i];
        // Candidate x values
        vector<ll> xs;
        
        // Add boundary cases
        xs.push_back(0);  // all T
        xs.push_back(max_x);  // all S
        
        // Add optimal x* candidates if valid
        if (A[i] * Q[i] + B[i] * P[i] != 0) {
            long double x_star = (long double)W * Q[i] / ( (long double)A[i]*Q[i] + (long double)B[i]*P[i] );
            ll xf = floor(x_star), xc = ceil(x_star);
            if (xf >= 0 && xf <= max_x) xs.push_back(xf);
            if (xc >= 0 && xc <= max_x && xc != xf) xs.push_back(xc);
            if (xf-1 >= 0 && xf-1 <= max_x) xs.push_back(xf-1);
            if (xf+1 >= 0 && xf+1 <= max_x) xs.push_back(xf+1);
            if (xc-1 >= 0 && xc-1 <= max_x && xc-1 != xf) xs.push_back(xc-1);
            if (xc+1 >= 0 && xc+1 <= max_x) xs.push_back(xc+1);
        }

        // Remove duplicates
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        for(ll x : xs){
            ll rem = W - A[i]*x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll cost = P[i]*x + Q[i]*y;
            if(cost < best) best = cost;
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
    // Lower bound: 0
    // Upper bound: minimum of sum of max possible W for each machine
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        ll max_A = X / P[i] * A[i];
        ll max_B = X / Q[i] * B[i];
        hi += max(max_A, max_B);
    }
    hi += 1;  // conservative upper bound

    // Binary search [lo, hi)
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(mid == 0 || cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo - 1 << "\n";
    return 0;
}