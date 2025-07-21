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

    multiset<ll> box_sizes;
    ll j = 0;
    ll min_required = -1;

    // Try to match smallest toys with smallest boxes
    for (ll i = 0; i < n; ++i) {
        while (j < n - 1 && B[j] < A[i]) {
            box_sizes.insert(B[j]);
            ++j;
        }

        if (box_sizes.size()) {
            // Use the smallest possible box that can fit A[i]
            auto it = box_sizes.lower_bound(A[i]);
            if (it != box_sizes.end()) {
                box_sizes.erase(it);
            } else {
                // No suitable box, need a new one
                min_required = A[i];
                break;
            }
        } else if (j < n - 1) {
            // We delay using this box until we find a toy it cannot fit
            ++j;
        } else {
            // No more boxes available, need one
            min_required = A[i];
            break;
        }
    }

    cout << min_required << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}