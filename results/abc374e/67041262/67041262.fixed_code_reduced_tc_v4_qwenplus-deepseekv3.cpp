#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    
    // Check both strategies with wider ranges
    ll x_max = W / a + 2;
    ll y_max = W / b + 2;
    
    // Strategy 1: Prefer a (x) when p*b < q*a
    if (p * b < q * a) {
        for (ll x = max(0LL, W / a - b); x <= min(x_max, W / a + b); x++) {
            ll rem = W - a * x;
            ll y = max(0LL, (rem + b - 1) / b);
            best = min(best, p * x + q * y);
        }
    } 
    // Strategy 2: Prefer b (y) otherwise
    else {
        for (ll y = max(0LL, W / b - a); y <= min(y_max, W / b + a); y++) {
            ll rem = W - b * y;
            ll x = max(0LL, (rem + a - 1) / a);
            best = min(best, p * x + q * y);
        }
    }
    
    // Also check boundary cases
    best = min(best, q * ((W + b - 1) / b));  // All y
    best = min(best, p * ((W + a - 1) / a));  // All x
    
    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
    }
    return sum <= X;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 1LL << 60;  // Larger upper bound
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}