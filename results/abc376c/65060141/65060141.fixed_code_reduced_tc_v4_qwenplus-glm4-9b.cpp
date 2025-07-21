#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }

    // Sort the toy sizes and the box sizes
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // Initialize variables
    ll ans = LLONG_MAX;  // This will store the minimum x needed
    bool found = false;  // Flag to indicate if a valid box size is found

    // Iterate through the toy sizes from the largest to the smallest
    for (ll i = n; i >= 1; i--) {
        // Try to place the current toy in the box
        ll j = n - 1;
        while (j >= 0 && b[j] < a[i]) {
            j--;
        }
        
        // Check if the toy can fit into an existing box or if we need to use the new box
        if (j >= 0 && b[j] >= a[i]) {
            // If so, we update the answer for the box size we are currently considering
            ans = min(ans, b[j]);
        } else {
            // If not, we need to use the new box with size at least a[i]
            ans = min(ans, a[i]);
            found = true;  // We found at least one valid configuration
        }
        
        // Since we sorted the box sizes, once we find a box that is too small, all previous ones are too small
        if (j == -1) break;
    }

    // Output the result
    if (found) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}