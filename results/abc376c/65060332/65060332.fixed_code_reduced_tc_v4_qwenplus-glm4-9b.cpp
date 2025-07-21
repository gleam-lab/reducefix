#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
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
    
    // We need to find the smallest box size x that can fit all toys
    // such that each toy fits into a box of size >= toy_size and no box is overfilled.
    // We also need to ensure that x is the minimum possible size.

    // To do this efficiently, we can use a two-pointer technique.
    // We will sort both arrays (toys and boxes) to match them by size.
    sort(a, a + n);
    sort(b, b + n - 1);

    // Now we iterate through the boxes starting from the smallest.
    // For each box, we try to fit the largest remaining toy.
    ll j = 0; // Pointer for toys
    ll l = 0; // Pointer for boxes
    ll x = 0; // Minimum box size to fit all toys

    while (j < n) {
        // While there are toys that can fit in the current box
        while (j < n && a[j] <= b[l]) {
            j++;
        }
        // Now we need to find the smallest box size that can fit the remaining toys
        // We will use a binary search to find the minimum box size efficiently
        ll low = 1;
        ll high = b[l];
        while (low < high) {
            ll mid = (low + high + 1) / 2;
            ll count = 0;
            ll k = j;
            // Count how many toys can fit in a box of size 'mid'
            while (k < n && a[k] <= mid) {
                count++;
                k++;
            }
            // If count is more than total toys, then mid is too small
            if (count <= n - j) {
                high = mid - 1;
            } else {
                // Otherwise, mid could be a valid size
                low = mid;
            }
        }
        // Update x to be the maximum of x and low
        x = max(x, low);
        // Move to the next box
        l++;
    }

    // If x has been updated from its initial value, it's a valid size.
    // Otherwise, it means no such box size exists.
    if (x > 0) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}