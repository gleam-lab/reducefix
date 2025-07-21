#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, max_a = 0, min_diff = LLONG_MAX;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }

    // Sort the toy sizes and box sizes
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // Try to fit each toy into an existing box or find the smallest box size needed
    ll current_box_size = 0;
    for (ll i = 1; i <= n; i++) {
        if (i < n) {
            // Try to place the toy in the current box size
            if (b[i] >= a[i]) {
                current_box_size = b[i];
            } else {
                // If the toy is larger than current box size, calculate the minimum new box size needed
                min_diff = min(min_diff, a[i] - current_box_size);
            }
        } else {
            // The last toy must fit into a box of at least its size
            min_diff = min(min_diff, a[i]);
        }
    }

    // If the smallest new box size needed is greater than zero, print it
    if (min_diff > 0) {
        cout << min_diff;
    } else {
        // If all toys fit into the existing boxes, the minimum box size is zero
        cout << 0;
    }

    return 0;
}