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
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);

    ll smallest_x = LLONG_MAX;
    for (ll i = 0; i < n - 1; i++) {
        // The current box size and the smallest available box size for the current toy
        ll current_box_size = b[i];
        ll smallest_box_size = a[i + 1]; // Next toy size

        // Check if the current box size can accommodate the next toy
        if (current_box_size >= smallest_box_size) {
            // If so, update the smallest_x if needed
            smallest_x = min(smallest_x, current_box_size);
        } else {
            // Otherwise, we need to buy a new box of size smallest_box_size
            smallest_x = min(smallest_x, smallest_box_size);
        }
    }

    // If no box can accommodate the largest remaining toy, smallest_x will remain LLONG_MAX
    if (smallest_x == LLONG_MAX) {
        cout << -1;
    } else {
        cout << smallest_x;
    }

    return 0;
}