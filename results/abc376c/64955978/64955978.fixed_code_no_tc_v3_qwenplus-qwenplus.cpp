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

    // We will try to assign the largest toy to the largest available box
    ll j = 0; // pointer for boxes
    vector<bool> used(N - 1, false);
    ll required_x = -1;

    for (ll i = 0; i < N; ++i) {
        if (j < N - 1 && B[j] >= A[i]) {
            // Box available and can fit this toy
            j++;
        } else {
            // Need to assign this toy to the new box x
            if (required_x == -1) {
                required_x = A[i];
            } else {
                // Only one extra box is allowed, so second overflow means impossible
                cout << -1 << endl;
                return;
            }
        }
    }

    if (required_x != -1) {
        cout << required_x << endl;
    } else {
        // All toys fit into existing boxes, so x can be as small as possible (not needed)
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}