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

    multiset<ll> boxes;
    for (ll b : B) boxes.insert(b);

    ll required_x = -1;

    // Try to place the largest toy in a purchased box x
    // Then try to assign remaining toys greedily into available boxes
    for (ll i = n - 1; i >= 0; --i) {
        ll current_toy = A[i];
        auto it = boxes.upper_bound(current_toy);
        if (it != boxes.begin()) {
            // Can fit this toy in an existing box
            --it;
            boxes.erase(it);
        } else {
            // Cannot fit in any existing box, must use new box
            if (required_x == -1)
                required_x = current_toy;
            else {
                // More than one toy cannot be placed => impossible
                cout << -1 << endl;
                return;
            }
        }
    }

    if (required_x == -1) {
        // All toys could fit in existing boxes => minimum possible x is 1
        cout << 1 << endl;
    } else {
        cout << required_x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}