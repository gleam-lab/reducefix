#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // We need to find the minimal x such that we can assign all toys
    // First, try to match largest toys with largest available boxes
    ll j = 0;
    ll required_x = -1;

    for (ll i = 0; i < N; ++i) {
        if (j < N - 1 && B[j] >= A[i]) {
            j++;
        } else {
            // This toy must go into the new box
            if (required_x == -1) {
                required_x = A[i];
            } else {
                // Only one toy can go into the new box
                cout << -1 << endl;
                return;
            }
        }
    }

    if (required_x != -1) {
        cout << required_x << endl;
    } else {
        // All toys fit in existing boxes, so we still need to buy a box of at least smallest size
        // But since it's unused, technically any size is OK, but we must output the minimum x possible
        // So pick smallest B[N-2] or even smaller if allowed, but x must be positive
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}