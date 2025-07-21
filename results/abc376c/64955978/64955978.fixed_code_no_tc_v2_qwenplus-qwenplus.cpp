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

    // Try to fit the first N-1 toys into the existing boxes
    ll extra_toy = -1;
    ll b_idx = 0;

    for (ll a_idx = 0; a_idx < N; ++a_idx) {
        if (b_idx < N - 1 && A[a_idx] <= B[b_idx]) {
            b_idx++;
        } else {
            // This toy needs the new box
            if (extra_toy == -1) {
                extra_toy = A[a_idx];
            } else {
                // Can't have more than one toy in the new box
                cout << -1 << endl;
                return;
            }
        }
    }

    if (extra_toy == -1) {
        // All toys fit in existing boxes, so x can be as small as possible (just enough for one toy)
        // Find smallest box that is unused
        ll max_b = 0;
        for (ll i = 0; i < N - 1; ++i) {
            if (i >= b_idx) {
                max_b = B[i];
                break;
            }
        }
        cout << max_b << endl;
    } else {
        cout << extra_toy << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}