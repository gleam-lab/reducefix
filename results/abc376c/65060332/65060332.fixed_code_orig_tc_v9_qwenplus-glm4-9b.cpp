#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Find the minimum size `x` that can fit all toys.
    ll low = 1;  // Lower bound of `x`.
    ll high = 1e18;  // Upper bound of `x`.

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll canFit = 0;

        for (ll i = 0; i < n; i++) {
            // Check if toy `i` can fit in a box of size `mid`.
            if (a[i] <= mid) {
                canFit++;
            }
        }

        // Check if the number of toys that can fit is less than the number of boxes.
        if (canFit < n) {
            low = mid + 1;  // Increase the lower bound `x`.
        } else {
            high = mid - 1;  // Decrease the upper bound `x`.
        }
    }

    // Output the minimum `x` that can fit all toys.
    cout << low << endl;

    return 0;
}