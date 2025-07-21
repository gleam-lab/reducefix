#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // We need to find the smallest box size that can fit all toys
    // So we must find the maximum size that is still less than or equal to any existing box size
    // or any toy size that is not covered by existing boxes.
    
    // We will collect all sizes that are needed to be covered by the new box
    for (ll i = 0; i < n; ++i) {
        ll covered = false;
        for (ll j = 0; j < n - 1 && !covered; ++j) {
            if (a[i] <= b[j]) {
                covered = true;
            }
        }
        if (!covered) {
            c.push_back(a[i]);
        }
    }

    // If there are no additional sizes needed, the answer is 1 (any box can fit a toy of size 1)
    if (c.empty()) {
        cout << 1 << endl;
        return;
    }

    // We need to find the minimum box size that can cover all these sizes
    sort(c.begin(), c.end());
    ll minBoxSize = c[0];
    for (ll i = 1; i < c.size() && c[i] == minBoxSize; ++i) {
        minBoxSize++;
    }

    cout << minBoxSize << endl;
}

int main() {
    solve();
    return 0;
}