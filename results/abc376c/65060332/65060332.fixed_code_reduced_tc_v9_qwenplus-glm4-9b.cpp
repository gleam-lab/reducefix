#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N], box_sizes[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a, a + n); // Sort toy sizes
    sort(b, b + n - 1); // Sort box sizes
    
    ll l = 0, r = n - 2; // Initialize two pointers, l for toys and r for boxes
    ll min_x = LLONG_MAX; // Initialize minimum x to largest possible value
    
    // Try to fit toys into boxes from largest to smallest
    for (ll i = 0; i < n; ++i) {
        if (l >= r) { // If no more boxes can fit the current toy
            min_x = min(min_x, a[i]); // Check the next toy
            continue;
        }
        if (b[r] >= a[i]) { // If the largest box can fit the current toy
            r--; // Use the largest box
        } else if (b[l] >= a[i]) { // If the smallest box can fit the current toy
            l++; // Use the smallest box
        } else { // If no existing boxes can fit the current toy
            min_x = min(min_x, a[i]); // Consider a new box of size equal to the current toy
        }
    }
    
    if (min_x == LLONG_MAX) { // If no box can fit the current toy, return -1
        cout << -1 << endl;
    } else {
        cout << min_x << endl; // Otherwise, return the size of the new box
    }
    
    return 0;
}