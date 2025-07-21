#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    
    // Read toy sizes
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Read box sizes
    for(ll i = 1; i < n; i++) {
        cin >> b[i];
    }

    // Sort toy sizes in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    
    // Sort box sizes in ascending order
    sort(b + 1, b + n);

    ll ans = 0;
    for(ll i = 1, j = 1; i <= n; i++) {
        // If we have enough boxes left
        if(j < n) {
            // If current toy fits in the next box
            if(b[j] >= a[i]) {
                j++;  // Move to the next box
            } else {
                ans = max(ans, a[i]);  // Update the answer with current toy size
            }
        } else {
            ans = max(ans, a[i]);  // If no more boxes, update answer with current toy size
        }
    }

    cout << ans << endl;  // Print the result
    return 0;
}