#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimal cost to achieve work W for each step
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;  // Initialize to a value larger than X

        // The maximum number of S machines that could be needed
        ll max_x = (W + A[i] - 1) / A[i];

        // Function to calculate cost for a given x
        auto calculate_cost = [&](ll x) {
            if (x < 0) return LLONG_MAX;
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };

        // Check x = 0 (all T machines)
        best = min(best, calculate_cost(0));

        // Check x where all S machines are used
        best = min(best, calculate_cost(max_x));

        // Check x derived from the optimal point (continuous relaxation)
        if (A[i] != 0 && B[i] != 0) {
            long double x_star = (long double)W * Q[i] / ( (long double)A[i]*Q[i] + (long double)B[i]*P[i] );
            ll x_optimal = round(x_star);
            for (ll x = max(0LL, x_optimal - 2); x <= min(max_x, x_optimal + 2); ++x) {
                best = min(best, calculate_cost(x));
            }
        }

        total += best;
        if(total > X) return X + 1;  // Early exit if budget exceeded
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

    // Determine the upper bound for binary search
    ll max_W = 0;
    for(int i = 0; i < N; i++){
        ll max_A = (X / P[i]) * A[i];
        ll max_B = (X / Q[i]) * B[i];
        max_W += max(max_A, max_B);
    }
    ll lo = 0, hi = max_W + 1;

    // Binary search to find the maximum W
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