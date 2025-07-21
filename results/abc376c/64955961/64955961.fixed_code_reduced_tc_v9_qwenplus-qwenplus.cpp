#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset<ll> boxes;
    ll j = 0;
    ll min_needed = -1;

    // Try to match toys from largest to smallest
    for (ll i = n - 1; i >= 0; --i) {
        // Add all boxes that can potentially fit this toy
        while (j < n - 1 && b[j] < a[i]) {
            boxes.insert(b[j]);
            j++;
        }

        if (!boxes.empty()) {
            // Use the smallest possible box that fits the current toy
            auto it = boxes.upper_bound(a[i]);
            if (it != boxes.begin()) {
                --it;
                boxes.erase(it);
            } else {
                // No suitable box in current set, store this toy in new box
                if (min_needed == -1)
                    min_needed = a[i];
                else {
                    cout << -1 << endl;
                    return;
                }
            }
        } else {
            // No suitable box found, need to use new box
            if (min_needed == -1)
                min_needed = a[i];
            else {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << min_needed << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}