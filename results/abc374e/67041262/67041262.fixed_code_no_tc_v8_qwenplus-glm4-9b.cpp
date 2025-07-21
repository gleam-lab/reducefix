#include <iostream>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll best = LLONG_MAX;
    // Sã®å¹çãé«ãã¨ããxãå¤ç¨ãã
    if (p * b < q * a) {
        ll x0 = W / a;  // æå¤§å¯è½ãªxã®æ°
        for (ll x = x0; x >= 0; --x) {  // xã0ããx0ã¾ã§è©¦ã
            ll rem = W - a * x;  // å°ä½
            ll y = (rem + b - 1) / b;  //è¦ãªyã®æ°
            best = min(best, p * x + q * y);
        }
    }
    // Tã®å¹çãé«ãã¨ããyãå¤ç¨ãã
    else {
        ll y0 = W / b;  // æå¤§å¯è½ãªyã®æ°
        for (ll y = y0; y >= 0; --y) {  // yã0ããy0ã¾ã§è©¦ã
            ll rem = W - b * y;  // å°ä½
            ll x = (rem + a - 1) / a;  //è¦ãªxã®æ°
            best = min(best, p * x + q * y);
        }
    }
    return best;
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
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