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

    multiset<ll> boxSizes;
    for (ll b : B) boxSizes.insert(b);

    ll requiredBox = -1;

    // Try to place the largest toys first
    for (ll i = n - 1; i >= 0; --i) {
        auto it = boxSizes.lower_bound(A[i]);
        if (it != boxSizes.end()) {
            boxSizes.erase(it); // Use this box
        } else {
            // Cannot fit in any existing box, need new box of size A[i]
            if (requiredBox == -1) {
                requiredBox = A[i];
            } else {
                // More than one toy cannot be placed => impossible
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << requiredBox << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}