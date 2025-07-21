#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    
    // Input toy sizes and existing box sizes
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];
    
    // Sort the toy sizes and the box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Initialize pointers and variables
    ll l = 0, r = n - 1;
    ll maxToySizeInBox = 0;
    bool placedAllToys = true;
    
    // Check if all toys can be placed in existing boxes
    for (ll i = 0; i < n; ++i) {
        while (l <= r && b[l] < a[i]) {
            maxToySizeInBox = max(maxToySizeInBox, a[i]);
            l++;
        }
        if (b[r] < a[i]) {
            placedAllToys = false;
            break;
        }
        r--;
    }
    
    // Output the result
    if (!placedAllToys) {
        cout << -1 << endl;
    } else {
        cout << maxToySizeInBox << endl;
    }
    
    return 0;
}