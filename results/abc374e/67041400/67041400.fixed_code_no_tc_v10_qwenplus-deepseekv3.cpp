#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate the minimum cost to achieve W units for each process step
// Returns X+1 if it's impossible to achieve W within budget X
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++) {
        ll best = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];  // Maximum S machines needed
        
        // Function to calculate cost for a given x
        auto calc_cost = [&](ll x) {
            x = max(x, 0LL);
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };
        
        // Check all possible x that could potentially give minimum cost
        vector<ll> candidates;
        
        // 1. x = 0 (all T machines)
        candidates.push_back(0);
        
        // 2. x = max_x (all S machines)
        candidates.push_back(max_x);
        
        // 3. Optimal x derived from continuous relaxation
        if (A[i] != 0 && B[i] != 0) {
            long double x_star = (long double)W * Q[i] / ((long double)A[i]*Q[i] + (long double)B[i]*P[i]);
            ll x_floor = floor(x_star);
            ll x_ceil = ceil(x_star);
            
            candidates.push_back(x_floor);
            candidates.push_back(x_ceil);
            
            // Add nearby points to ensure we don't miss the minimum
            for (int dx = -2; dx <= 2; dx++) {
                if (x_floor + dx >= 0 && x_floor + dx <= max_x)
                    candidates.push_back(x_floor + dx);
                if (x_ceil + dx >= 0 && x_ceil + dx <= max_x)
                    candidates.push_back(x_ceil + dx);
            }
        }
        
        // Remove duplicates and check all candidates
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        for (ll x : candidates) {
            if (x < 0 || x > max_x) continue;
            ll cost = calc_cost(x);
            if (cost < best) best = cost;
        }
        
        total += best;
        if (total > X) return X + 1;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++) {
        ll max_possible = max(X / P[i] * A[i], X / Q[i] * B[i]);
        hi = max(hi, max_possible);
    }
    hi += 1;  // To account for possible rounding

    // Binary search on [lo, hi)
    while(lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}