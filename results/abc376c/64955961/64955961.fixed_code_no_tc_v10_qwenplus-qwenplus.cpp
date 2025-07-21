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

    ll extra_box_needed = -1;

    // Try to match largest toys with largest available boxes
    ll j = N - 2; // index for B
    for (ll i = N - 1; i >= 0; --i) {
        if (j >= 0 && A[i] <= B[j]) {
            j--; // use this box
        } else {
            // This toy cannot fit in any remaining box, we need a new box for it
            extra_box_needed = A[i];
        }
    }

    cout << extra_box_needed << endl;
}

int main() {
    solve();
    return 0;
}