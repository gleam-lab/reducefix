#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve the desired capability
ll cost_for_W(int N, ll W, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = X + 1;
        
        // Generate all possible x values
        vector<ll> possible_xs = {0, (W + A[i] - 1) / A[i], (W + B[i] - 1) / B[i]};
        ll A_multiplier = (W + A[i] - 1) / A[i];
        ll B_multiplier = (W + B[i] - 1) / B[i];
        
        // Calculate the optimal x value using the formula provided
        long double x_star = (long double)W * Q[i] / (A_multiplier * Q[i] + B_multiplier * P[i]);
        ll x_floor = floor(x_star);
        ll x_ceil = ceil(x_star);
        possible_xs.push_back(x_floor - 1);
        possible_xs.push_back(x_floor);
        possible_xs.push_back(x_floor + 1);
        possible_xs.push_back(x_ceil);
        possible_xs.push_back(x_ceil + 1);
        
        // Filter valid x values
        sort(possible_xs.begin(), possible_xs.end());
        auto end = unique(possible_xs.begin(), possible_xs.end());
        possible_xs.erase(end, possible_xs.end());
        
        // Calculate the minimum cost for each x
        for (ll x : possible_xs) {
            if (x < 0 || x > max(A_multiplier, B_multiplier)) continue;
            ll y = (x < A_multiplier) ? (W - A[i] * x) / B[i] : 0;
            ll c = P[i] * x + Q[i] * y;
            min_cost = min(min_cost, c);
        }

        total_cost += min_cost;
        if (total_cost > X) return X + 1;
    }
    return total_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = X + 1;

    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}