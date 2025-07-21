#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Returns the minimum cost to achieve total capacity W
// Returns X+1 if it's not possible within budget X
ll cost_for_W(int N, ll W, ll X,
              const vector<ll>& A, const vector<ll>& P,
              const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        ll best = X + 1;

        // Candidate x values to try
        vector<ll> xs = {0};

        // Continuous relaxation optimal x*
        long double x_star = (long double)W * Q[i] / (A[i] * Q[i] + B[i] * P[i]);
        ll xf = floor(x_star);
        ll xc = ceil(x_star);

        // Safely add nearby integer candidates around x_star
        if (xf - 1 >= 0) xs.push_back(xf - 1);
        xs.push_back(xf);
        xs.push_back(xc);
        if (xc + 1 >= 0) xs.push_back(xc + 1);

        // Also consider using only T machines (x = 0), and only S machines (y = 0)
        xs.push_back((W + A[i] - 1) / A[i]);  // Max x for S-only

        // Remove duplicates
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        ll max_x = (W + A[i] - 1) / A[i];
        for (ll x : xs) {
            if (x < 0 || x > max_x) continue;

            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];

            ll c = P[i] * x + Q[i] * y;
            if (c < best) best = c;
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
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Estimate upper bound for binary search
    long double best_ratio = 0;
    for (int i = 0; i < N; ++i) {
        best_ratio = max(best_ratio, (long double)A[i] / P[i]);
        best_ratio = max(best_ratio, (long double)B[i] / Q[i]);
    }
    ll lo = 0, hi = (ll)(X * best_ratio) + 2;

    // Binary search on maximum achievable W
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X)
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << "\n";
    return 0;
}