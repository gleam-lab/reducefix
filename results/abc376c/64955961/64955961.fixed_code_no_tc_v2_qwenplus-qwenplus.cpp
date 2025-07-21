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

    // We need to find the minimal x such that we can assign all toys to boxes
    // Try to match largest toys with largest available boxes (greedily)
    ll j = N - 2; // index for B (boxes)
    ll required_box_size = -1;

    for (ll i = N - 1; i >= 0; --i) { // index for A (toys)
        if (j >= 0 && B[j] >= A[i]) {
            j--; // box used
        } else {
            // This toy needs the new box
            if (required_box_size == -1)
                required_box_size = A[i];
            else {
                // More than one toy requires a new box -> impossible
                cout << -1 << endl;
                return;
            }
        }
    }

    if (required_box_size == -1) {
        // All toys could be placed without the new box
        // But we still need to buy one, choose smallest possible (>= smallest toy)
        cout << A[0] << endl;
    } else {
        cout << required_box_size << endl;
    }
}

int main() {
    solve();
}