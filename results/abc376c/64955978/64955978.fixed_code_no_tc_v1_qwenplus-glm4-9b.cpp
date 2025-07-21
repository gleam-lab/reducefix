#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    
    // Read sizes for toys and boxes
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N-1; i++) {
        cin >> B[i];
    }

    // Sort the sizes of toys and boxes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // Initialize the minimum box size x
    ll x = LLONG_MAX;
    
    // Check if there's a need to buy a new box
    for (ll i = 0; i < N-1; i++) {
        if (A[i] < B[i]) {
            // If toy A[i] cannot fit in box B[i], increment i to find a suitable box
            while (i < N-1 && A[i] < B[i]) {
                i++;
            }
            // If no suitable box is found, or the next box is also not suitable
            if (i == N-1 || A[i] < B[i]) {
                cout << -1 << endl;
                return;
            }
            // Update the minimum box size x
            x = min(x, A[i]);
        }
    }

    // If all toys fit in existing boxes, no new box is needed
    if (x == LLONG_MAX) {
        cout << 0 << endl;
        return;
    }

    // Output the minimum box size x
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}