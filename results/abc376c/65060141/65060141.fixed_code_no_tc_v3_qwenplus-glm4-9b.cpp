#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];
int main() {
    ll n, mx = 0;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i < n) {
            cin >> b[i];
            // Update the maximum toy size that needs to be placed in boxes
            mx = max(mx, a[i]);
        }
    }
    // Iterate over each box size in reverse
    for (ll i = n - 1; i >= 0; --i) {
        // If the current box size is large enough for the largest toy, print and exit
        if (b[i] >= mx) {
            cout << mx;
            return 0;
        }
    }
    // If no box size is large enough, print -1
    cout << -1;
    return 0;
}