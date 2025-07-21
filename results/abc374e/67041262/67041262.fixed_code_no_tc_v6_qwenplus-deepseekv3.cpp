#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Check both x and y as primary variables
    ll max_x = W / a;
    for (ll dx = 0; dx <= 100 && dx <= max_x; dx++) {
        ll x = max_x - dx;
        ll rem = W - a * x;
        ll y = (rem <= 0 ? 0 : (rem + b - 1) / b);
        best = min(best, p * x + q * y);
    }
    
    ll max_y = W / b;
    for (ll dy = 0; dy <= 100 && dy <= max_y; dy++) {
        ll y = max_y - dy;
        ll rem = W - b * y;
        ll x = (rem <= 0 ? 0 : (rem + a - 1) / a);
        best = min(best, p * x + q * y);
    }
    
    // Also check near the crossover point
    for (ll x = 0; x <= 100 && x * a <= W; x++) {
        ll rem = W - a * x;
        ll y = (rem <= 0 ? 0 : (rem + b - 1) / b);
        best = min(best, p * x + q * y);
    }
    
    for (ll y = 0; y <= 100 && y * b <= W; y++) {
        ll rem = W - b * y;
        ll x = (rem <= 0 ? 0 : (rem + a - 1) / a);
        best = min(best, p * x + q * y);
    }
    
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

    ll lo = 0, hi = 1000000000000LL; // 上限は十分大きく
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}