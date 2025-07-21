#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
    }
    
    // Sort toys and boxes in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    sort(b + 1, b + n, greater<ll>());
    
    ll required_toys = 0;
    ll j = 1;
    
    // Try to fit the largest toys into the largest available boxes
    for (ll i = 1; i <= n; ++i) {
        if (j < n && b[j] >= a[i]) {
            j++;
        } else {
            required_toys++;
            if (required_toys > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // If we need one toy to be placed in the new box, its size must be at least a[i]
    if (required_toys == 1) {
        cout << a[n] << endl;
    } else {
        // All toys were fitted, so x can be 0 (but minimum positive integer is 1)
        cout << 1 << endl;
    }
    
    return 0;
}