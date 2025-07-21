#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, cnt = 0, mx = 0;
    cin >> n;
    
    // Read toy sizes
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Read box sizes
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }
    
    // Sort toy sizes in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    
    // Sort box sizes in ascending order
    sort(b + 1, b + n);
    
    ll j = 0;
    for (ll i = 1; i <= n; i++) {
        if (j >= n - 1 || a[i] > b[j]) { // If no more boxes available or current toy is too big
            cnt++; // Need a new box
            mx = max(mx, a[i]); // Update the maximum toy size needed
        } else {
            j++; // Move to the next box
        }
    }
    
    if (cnt > 1) {
        cout << -1;
    } else {
        cout << mx;
    }
    
    return 0;
}