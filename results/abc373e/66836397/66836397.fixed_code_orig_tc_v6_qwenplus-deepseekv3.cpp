#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll &a : A) {
        cin >> a;
        total += a;
    }
    ll remaining = K - total;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());

    // The M-th largest value is the threshold
    ll threshold = (M <= N) ? sorted_A[M - 1] : 0;

    for (ll i = 0; i < N; ++i) {
        ll current = A[i];
        if (current >= threshold) {
            cout << 0 << " \n"[i == N - 1];
        } else {
            ll needed = threshold - current;
            if (needed <= remaining) {
                cout << needed << " \n"[i == N - 1];
            } else {
                cout << -1 << " \n"[i == N - 1];
            }
        }
    }
    return 0;
}