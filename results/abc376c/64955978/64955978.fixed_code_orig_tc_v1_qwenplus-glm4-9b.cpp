#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    // Sort both toys and boxes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // The minimum box size needed must be at least the size of the largest toy
    ll x = A[0]; // Start with the largest toy

    // Try to fit each toy into the current box size `x`
    for (ll i = 0; i < N - 1; ++i) {
        // If the current box is larger than or equal to the toy, it's a candidate
        if (B[i] >= A[i + 1]) {
            // Update `x` to the size of this box (since it's a candidate for the smallest box)
            x = B[i];
        } else {
            // If we can't fit the next toy, no solution exists
            cout << -1 << endl;
            return 0;
        }
    }

    // If all toys fit into the largest box, then `x` is the smallest box size needed
    cout << x << endl;

    return 0;
}