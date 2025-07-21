#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_cost(ll W, ll a, ll p, ll b, ll q) {
    ll cost_a = (W + a - 1) / a * p;
    ll cost_b = (W + b - 1) / b * q;
    return min(cost_a, cost_b);
}

bool can(ll W, int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
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

    ll lo = 0, hi = 1000000000000LL;
    while (hi - lo > 1) {
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}