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

    // We will try to fit the first N-1 toys into the N-1 boxes
    // The largest toy must go into the purchased box, so x must be >= A[0]
    // Then we check if the remaining toys can be matched with boxes

    // If the second largest toy cannot fit in any box, it's impossible
    // Compare each of the remaining N-1 toys with the corresponding box
    for (ll i = 1; i < N; ++i) {
        if (A[i] > B[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }

    // Minimum required size of the extra box is the size of the largest toy
    cout << A[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}