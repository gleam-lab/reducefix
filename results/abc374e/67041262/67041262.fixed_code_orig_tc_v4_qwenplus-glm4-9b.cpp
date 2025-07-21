#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q){
    ll best = LLONG_MAX;
    if (p * b < q * a) {
        ll x0 = W / a;  // floor
        for (ll dx = 0; dx <= b && x0 >= dx; dx++){
            ll x = x0 - dx;
            ll rem = W - a * x;
            ll y = (rem <= 0 ? 0 : (rem + b - 1) / b);
            best = min(best, p * x + q * y);
        }
    } else {
        ll y0 = W / b;
        for (ll dy = 0; dy <= a && y0 >= dy; dy++){
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

    ll lo = 0, hi = 1000000000000LL; // ä¸éã¯ååå¤§ãã
    while (hi - lo > 1){
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo + 1 << "\n"; // Output should be lo + 1 because the loop exits when hi = lo
    return 0;
}