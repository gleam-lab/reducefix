#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

ll minBoxSizeForToys(ll n, ll arr[], ll boxSize) {
    // Iterate from largest toy to smallest toy
    for (ll i = n; i >= 1; --i) {
        // If current toy can be placed in the box of size `boxSize`, then return it
        if (arr[i] <= boxSize) {
            return boxSize;
        }
    }
    // If no box can accommodate the largest toy, return -1
    return -1;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // Sort toy sizes in ascending order
    sort(a + 1, a + n + 1);
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
    }
    // Sort box sizes in ascending order
    sort(b + 1, b + n);
    // Try each box size from the largest box to the smallest box
    for (ll i = n - 1; i >= 0; --i) {
        ll boxSize = b[i];
        ll minSize = minBoxSizeForToys(n, a, boxSize);
        if (minSize != -1) {
            cout << minSize;
            return 0;
        }
    }
    // If no valid box size is found, return -1
    cout << -1;
    return 0;
}