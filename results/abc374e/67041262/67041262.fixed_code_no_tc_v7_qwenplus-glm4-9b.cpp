#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // S (a, p)ã®å¹çãåºæºã«xã¨yã®ä½¿ç¨ãæ±ºå®
    if (p * b <= q * a) {
        // Sãä¸»ã«ä½¿ç¨
        ll x0 = W / a;  // Sã®åä½ç©åã®æå¤§åæ°
        for (ll dx = 0; dx <= b && x0 >= dx; ++dx) {
            ll x = x0 - dx;
            ll y = (W - a * x + b - 1) / b;  // yã®åä½ç©åã®æå°åæ°
            best = min(best, p * x + q * y);
        }
    } else {
        // T (b, q)ãä¸»ã«ä½¿ç¨
        ll y0 = W / b;  // Tã®åä½ç©åã®æå¤§åæ°
        for (ll dy = 0; dy <= a && y0 >= dy; ++dy) {
            ll y = y0 - dy;
            ll x = (W - b * y + a - 1) / a;  // xã®åä½ç©åã®æå°åæ°
            best = min(best, p * x + q * y);
        }
    }
    return best;
}

bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
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
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = 1000000000000LL;  // ä¸éã¯ååå¤§ãã
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}