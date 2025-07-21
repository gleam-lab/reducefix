#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    
    vector<ll> A(N), B(N - 1);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in descending order of sizes
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    // Try to fit the first N-1 toys into the N-1 boxes
    ll extra_toy = -1; // Will store the index of the toy that can't be placed in any box
    vector<bool> used(N - 1, false); // Track which boxes are used

    ll b_idx = 0;
    for (ll a_idx = 0; a_idx < N && b_idx < N - 1; ++a_idx) {
        if (A[a_idx] <= B[b_idx]) {
            b_idx++;
        } else {
            extra_toy = a_idx;
        }
    }

    // If we found at most one toy that couldn't be placed, then it's possible
    if (extra_toy == -1 || b_idx == N - 1) {
        // All toys except possibly one were placed
        cout << A[extra_toy == -1 ? N - 1 : extra_toy] << endl;
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