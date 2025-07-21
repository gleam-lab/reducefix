#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Determine which resource is more cost-effective per unit
    ll best = LLONG_MAX;
    if (p * b < q * a) {
        // If S is cheaper, use it as much as possible
        ll x0 = W / a;            // Floor division to get the maximum number of S that can be used
        for (ll dx = 0; dx <= b && x0 >= dx; dx++) {
            ll x = x0 - dx;
            ll rem = W - a * x;
            ll y = (rem <= 0 ? 0 : (rem + b - 1) / b); // Ceiling division to get the minimum number of T needed
            best = min(best, p * x + q * y);
        }
    } else {
        // If T is cheaper, use it as much as possible
        ll y0 = W / b;
        for (ll dy = 0; dy <= a && y0 >= dy; dy++) {
            ll y = y0 - dy;
            ll rem = W - b * y;
            ll x = (rem <= 0 ? 0 : (rem + a - 1) / a);
            best = min(best, p * x + q * y);
        }
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

    ll lo = 0, hi = 1000000000000LL; // Upper bound set sufficiently large
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}