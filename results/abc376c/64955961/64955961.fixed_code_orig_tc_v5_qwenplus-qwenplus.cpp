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

    // Use multiset to handle multiple identical boxes
    multiset<ll> boxSizes;
    for (ll b : B) boxSizes.insert(b);

    ll needed = 0;

    // Try to fit the smallest toys into the smallest boxes
    for (ll i = 0; i < n; ++i) {
        auto it = boxSizes.lower_bound(A[i]);
        if (it != boxSizes.end()) {
            // Found a suitable box, use it
            boxSizes.erase(it);
        } else {
            // No suitable box found, we need our own box for this toy
            needed++;
        }
    }

    if (needed == 0) {
        cout << "-1\n";
    } else {
        // The largest toy that couldn't be placed determines the minimal x
        sort(A.rbegin(), A.rend());
        cout << A[needed - 1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}