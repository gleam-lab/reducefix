#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve W work for each process
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = X + 1;

        // Calculate the maximum x needed if only S-type machines are used
        ll max_x = (W + A[i] - 1) / A[i];
        
        // The optimal x might be around W*Q[i]/(A[i]*Q[i] + B[i]*P[i])
        ll x_star_num = W * Q[i];
        ll x_star_den = A[i] * Q[i] + B[i] * P[i];
        ll x_star = x_star_num / x_star_den;
        
        // Check x candidates around x_star to find the minimal cost
        for (ll x = max(0LL, x_star - 2); x <= x_star + 2; ++x) {
            if (x > max_x) continue;
            ll remaining_work = W - A[i] * x;
            ll y = (remaining_work <= 0) ? 0 : (remaining_work + B[i] - 1) / B[i];
            ll cost = P[i] * x + Q[i] * y;
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        
        // Also check the boundary cases where x is 0 or max_x
        ll x = 0;
        ll remaining_work = W - A[i] * x;
        ll y = (remaining_work <= 0) ? 0 : (remaining_work + B[i] - 1) / B[i];
        ll cost = P[i] * x + Q[i] * y;
        if (cost < min_cost) {
            min_cost = cost;
        }
        
        x = max_x;
        remaining_work = W - A[i] * x;
        y = (remaining_work <= 0) ? 0 : (remaining_work + B[i] - 1) / B[i];
        cost = P[i] * x + Q[i] * y;
        if (cost < min_cost) {
            min_cost = cost;
        }
        
        total_cost += min_cost;
        if (total_cost > X) {
            return X + 1;
        }
    }
    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for (int i = 0; i < N; ++i) {
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi += 1;

    // Binary search to find the maximum W achievable within budget X
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo - 1 << "\n";
    return 0;
}