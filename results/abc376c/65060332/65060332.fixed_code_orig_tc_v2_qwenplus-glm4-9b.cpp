#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n - 1; i++) cin >> b[i];
    
    // Sort the toy sizes and the box sizes
    sort(a, a + n);
    sort(b, b + n - 1);
    
    ll min_x = LLONG_MAX; // Initialize the minimum x as maximum possible long long value
    ll j = 0; // Pointer for the box sizes
    
    // Iterate through the toy sizes
    for (ll i = 0; i < n; i++) {
        // Move the box pointer to the largest box that can accommodate the current toy
        while (j < n - 1 && b[j] < a[i]) j++;
        
        // If the current box can accommodate the toy, move to the next toy
        if (j < n - 1 && b[j] >= a[i]) continue;
        
        // Otherwise, we need to consider purchasing a new box
        if (i < n - 1) {
            min_x = min(min_x, a[i + 1] - 1);
        } else {
            // If we are at the last toy, we need the minimum box size to be at least the size of the last toy
            min_x = min(min_x, a[i]);
        }
    }
    
    // Output the result
    if (min_x == LLONG_MAX) cout << -1 << endl;
    else cout << min_x << endl;
    
    return 0;
}