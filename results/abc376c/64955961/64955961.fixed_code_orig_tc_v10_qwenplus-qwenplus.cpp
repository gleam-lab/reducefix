#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);
    for (ll i = 0; i < n; ++i) cin >> A[i];
    for (ll i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Try to match smallest toys with smallest boxes
    ll i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    // If all toys are matched, no extra box needed
    if (i == n) {
        cout << -1 << endl;
        return;
    }

    // Otherwise, the unmatched toy needs a new box
    cout << A.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}