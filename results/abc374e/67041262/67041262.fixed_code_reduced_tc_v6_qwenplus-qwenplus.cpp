#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculates the minimum cost to achieve at least W units of coverage
ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Ensure W is non-negative
    if (W <= 0) return 0;

    // Try using more of the more cost-efficient item first
    ll best = LLONG_MAX;

    // Compare efficiency: cost per unit of a vs b
    if (p * b < q * a) {
        // S is more efficient -> try reducing y from an upper bound
        ll x0 = (W + a - 1) / a; // ceil division
        for (ll dx = max(0LL, x0 - b); dx <= x0 + b && dx >= 0; dx++) {
            ll x = dx;
            ll rem = max(0LL, W - a * x);
            ll y = (rem + b - 1) / b; // ceil division
            best = min(best, p * x + q * y);
        }
    } else {
        // T is more efficient -> try reducing x from an upper bound
        ll y0 = (W + b - 1) / b; // ceil division
        for (ll dy = max(0LL, y0 - a); dy <= y0 + a && dy >= 0; dy++) {
            ll y = dy;
            ll rem = max(0LL, W - b * y);
            ll x = (rem + a - 1) / a; // ceil division
            best = min(best, p * x + q * y);
        }
    }

    return best;
}

// Checks whether it's possible to achieve total weight W with total cost <= X
bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q){
    ll sum = 0;
    for (int i = 0; i < N; i++){
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
    }
    return sum <= X;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 1e18; // hi should be large enough for constraints
    while (hi - lo > 1){
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}