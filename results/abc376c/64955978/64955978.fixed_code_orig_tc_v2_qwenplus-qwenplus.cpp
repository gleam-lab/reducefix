#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> toys(A.begin(), A.end());
    ll required = -1;

    // Try to assign smallest boxes to largest toys as possible
    for (ll i = N - 2; i >= 0; --i) {
        auto it = toys.lower_bound(B[i]);
        if (it != toys.begin()) {
            --it;
            toys.erase(it);
        } else {
            required = B[i];
        }
    }

    if (toys.size() == 1 && (required == -1 || *toys.begin() <= required)) {
        cout << max(*toys.begin(), required) << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}