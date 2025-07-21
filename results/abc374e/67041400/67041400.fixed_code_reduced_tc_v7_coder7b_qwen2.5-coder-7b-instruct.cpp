#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve at least W with budget X
ll cost_for_W(int N, ll W, ll X,
              const vector<ll>& A, const vector<ll>& P,
              const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        // Calculate the minimum cost to achieve capability W for process i
        ll best = X + 1;

        // Generate candidate values for x
        vector<ll> xs;
        xs.push_back(0);
        xs.push_back((W + A[i] - 1) / A[i]);  // All Si
        // Optimal x* from continuous relaxation
        long double x_star = (long double)W * Q[i] / ((long double)A[i]*Q[i] + (long double)B[i]*P[i]);
        ll xf = floor(x_star), xc = ceil(x_star);
        xs.push_back(xf-1);
        xs.push_back(xf);
        xs.push_back(xf+1);
        xs.push_back(xc);
        xs.push_back(xc+1);
        xs.push_back((W + B[i] - 1) / B[i]);  // All Ti as 'x' (S is 0 machines)

        // Remove duplicates and keep only valid range
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ll max_x = (W + A[i] - 1) / A[i];
        for(ll x: xs){
            if(x < 0 || x > max_x) continue;
            // Calculate remaining capacity and corresponding y
            ll rem = W - A[i]*x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            ll c = P[i]*x + Q[i]*y;
            if(c < best) best = c;
        }

        total += best;
        if(total > X) return X+1;  // Early exit if budget exceeded
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
    // Upper bound W_hi is an estimate of achieving full budget with the most efficient machine
    long double best_ratio = 0;
    for(int i = 0; i < N; i++){
        best_ratio = max(best_ratio, (long double)A[i] / P[i]);
        best_ratio = max(best_ratio, (long double)B[i] / Q[i]);
    }
    ll lo = 0, hi = (ll)floor(X * best_ratio) + 1;

    // Binary search over [lo, hi)
    while(lo + 1 < hi){
        ll mid = lo + (hi - lo) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;  // mid is achievable
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}