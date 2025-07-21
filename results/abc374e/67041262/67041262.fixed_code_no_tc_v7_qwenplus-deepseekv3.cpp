#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Check both possible optimal directions
    for (int direction = 0; direction < 2; ++direction) {
        if (direction == 0) {
            // Try using x (a) as much as possible
            ll max_x = W / a;
            for (ll x = max(max_x - 200, 0LL); x <= min(max_x + 200, W / a + 1); ++x) {
                ll rem = W - a * x;
                if (rem < 0) continue;
                ll y = (rem + b - 1) / b;
                best = min(best, p * x + q * y);
            }
        } else {
            // Try using y (b) as much as possible
            ll max_y = W / b;
            for (ll y = max(max_y - 200, 0LL); y <= min(max_y + 200, W / b + 1); ++y) {
                ll rem = W - b * y;
                if (rem < 0) continue;
                ll x = (rem + a - 1) / a;
                best = min(best, p * x + q * y);
            }
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

    ll lo = 0, hi = 0;
    // First find a suitable upper bound
    for (int i = 0; i < N; i++) {
        hi = max(hi, max(A[i], B[i]));
    }
    hi = max(hi, 1LL) * (X / min(*min_element(P.begin(), P.end()), 
                                *min_element(Q.begin(), Q.end())) + 1);

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (can(mid, N, X, A, P, B, Q)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}