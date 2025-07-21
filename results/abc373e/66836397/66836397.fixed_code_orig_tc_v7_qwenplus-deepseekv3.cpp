#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll rem = K - sum;

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());
    ll threshold = (M <= N) ? sortedA[M-1] : 0;

    for (ll i = 0; i < N; ++i) {
        if (A[i] >= threshold) {
            cout << "0 ";
        } else {
            ll needed = threshold - A[i];
            if (needed <= rem) {
                cout << needed << " ";
            } else {
                cout << "-1 ";
            }
        }
    }
    cout << "\n";

    return 0;
}