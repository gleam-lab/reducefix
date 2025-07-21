#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Sort both arrays to make comparison easier
    sort(a, a + n);
    sort(b, b + n);

    // We will try to place all toys in the smallest possible box
    bool isPossible = true;
    ll minBoxSize = LLONG_MAX;

    // Check if we can use one of the existing boxes
    bool usedExistingBox = false;
    for (ll i = 0; i < n - 1; i++) {
        if (a[n - 1] <= b[i]) {
            // We can use box b[i] to place the largest toy
            minBoxSize = min(minBoxSize, b[i]);
            usedExistingBox = true;
            break;
        }
    }

    // If we cannot use any existing box, we need to decide on a new box size
    if (!usedExistingBox) {
        ll j = n - 2;
        ll sumSizes = 0;
        bool allPlaced = true;

        // Try to place each toy starting from the largest
        for (ll i = n - 1; i >= 0; i--) {
            while (j >= 0 && a[i] <= b[j]) {
                // Box b[j] can be used to place toy a[i]
                j--;
            }
            if (j < 0) {
                // No suitable box found for toy a[i]
                allPlaced = false;
                break;
            }
            // Calculate the total size of toys that could be placed in box b[j]
            sumSizes += b[j];
            j--;
        }

        // If not all toys could be placed, print -1
        if (!allPlaced) {
            cout << -1 << endl;
            return;
        }

        // The new box size needs to be at least the sum of all boxes plus the largest toy
        minBoxSize = a[n - 1] + sumSizes;
    }

    // Output the minimum box size we found
    cout << minBoxSize << endl;
}

int main() {
    solve();
    return 0;
}