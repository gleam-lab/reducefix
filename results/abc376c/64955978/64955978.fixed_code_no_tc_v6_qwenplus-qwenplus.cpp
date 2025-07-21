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

    // We will try to fit the largest toys into the largest boxes
    // The toy that cannot be placed will be put in the new box, we need to find its size

    ll b_idx = 0;
    ll required_size = -1;

    for (ll i = 0; i < N; ++i) {
        if (b_idx < N - 1 && B[b_idx] >= A[i]) {
            b_idx++;
        } else {
            // This toy must go into the purchased box
            if (required_size == -1) {
                required_size = A[i];
            } else {
                // Since we can only buy one box, we can't place more than one toy in it
                cout << -1 << endl;
                return;
            }
        }
    }

    if (required_size == -1) {
        // All toys were placed in existing boxes, so we can buy a box of size 1 (minimum possible)
        cout << 1 << endl;
    } else {
        cout << required_size << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}