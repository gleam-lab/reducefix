#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate minimum cost to achieve W, return X+1 if impossible within budget X
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;

        // Generate candidate x values
        vector<ll> xs;
        xs.push_back(0);  // all Ti
        ll x_all_S = (W + A[i] - 1) / A[i];
        xs.push_back(x_all_S);  // all Si
        ll x_all_T = (W + B[i] - 1) / B[i];

        // Optimal point candidates
        long double x_star = (long double)W * Q[i] / ((long double)A[i]*Q[i] + (long double)B[i]*P[i]);
        for(ll dx = -2; dx <= 2; dx++){
            ll x = llround(x_star) + dx;
            if(x >= 0) xs.push_back(x);
        }

        // Remove duplicates and sort
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        // Evaluate each candidate x
        for(ll x : xs){
            if(x < 0) continue;
            ll rem = W - A[i] * x;
            if(rem < 0) continue;  // x too large
            ll y = (rem <= 0) ? 0 : (rem + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if(cost < best) best = cost;
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

    // Better upper bound estimation
    ll lo = 0, hi = 0;
    for(int i = 0; i < N; i++){
        ll max_possible = max(X / P[i] * A[i], X / Q[i] * B[i]);
        hi = max(hi, max_possible);
    }
    hi += 1;  // conservative upper bound

    // Binary search
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