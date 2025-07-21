#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N], mx = LLONG_MAX;
int main() {
    ll n;
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
    
    // Find the smallest box size that can accommodate all toys
    ll bx = LLONG_MAX;
    for (ll i = 1; i <= n; i++) {
        if (a[i] <= b[i - 1]) {
            bx = min(bx, b[i - 1]);
        }
    }
    
    // If there is no such box, output -1
    if (bx == LLONG_MAX) {
        cout << -1;
    } else {
        // Output the smallest size of the additional box needed
        cout << bx;
    }
    return 0;
}