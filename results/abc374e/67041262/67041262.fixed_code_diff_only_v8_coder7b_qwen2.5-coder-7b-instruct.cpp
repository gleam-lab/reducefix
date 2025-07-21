#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    // Choose the more cost-effective option between using 'a' or 'b'
    if (p * b < q * a) {
        // Using 'b' is more cost-effective
        ll y0 = W / b;
        for (ll dy = 0; dy <= a && y0 >= dy; ++dy) {
            ll y = y0 - dy;
            ll rem = W - b * y;
            ll x = (rem <= 0 ? 0 : (rem + a - 1) / a);
            return p * x + q * y;
        }
    } else {
        // Using 'a' is more cost-effective
        ll x0 = W / a;
        for (ll dx = 0; dx <= b && x0 >= dx; ++dx) {
            ll x = x0 - dx;
            ll rem = W - a * x;
            ll y = (rem <= 0 ? 0 : (rem + b - 1) / b);
            return p * x + q * y;
        }
    }
    return LLONG_MAX; // Should never reach here
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += min_cost(W, A[i], P[i], B[i], Q[i]);
        if (sum > X) return false;
    }
    return true;
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

    ll lo = 0, hi = 1000000000000LL; // Upper limit is sufficiently large
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}