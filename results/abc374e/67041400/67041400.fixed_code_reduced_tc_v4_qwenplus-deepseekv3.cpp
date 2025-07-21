#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; ++i) {
        ll best = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];
        
        vector<ll> xs;
        xs.push_back(0);
        xs.push_back(max_x);
        long double x_star = (long double)W * Q[i] / ((long double)A[i] * Q[i] + (long double)B[i] * P[i]);
        ll x_floor = floor(x_star), x_ceil = ceil(x_star);
        for (ll x : {x_floor - 1, x_floor, x_floor + 1, x_ceil - 1, x_ceil, x_ceil + 1}) {
            if (x >= 0 && x <= max_x) {
                xs.push_back(x);
            }
        }
        
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        for (ll x : xs) {
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
    
    long double best_ratio = 0;
    for (int i = 0; i < N; ++i) {
        best_ratio = max(best_ratio, (long double)A[i] / P[i]);
        best_ratio = max(best_ratio, (long double)B[i] / Q[i]);
    }
    ll hi = (ll)floor(X * best_ratio) + 1;
    ll lo = 0;
    
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << lo << '\n';
    return 0;
}