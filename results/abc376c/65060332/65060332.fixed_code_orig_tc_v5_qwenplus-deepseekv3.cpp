#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    
    ll i = 0, j = 0;
    ll cnt = 0;
    ll mx_unmatched = 0;
    
    while (i < n && j < n - 1) {
        if (b[j] >= a[i]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i >= n - 1) {
        // All but at most one toy can be placed in existing boxes
        if (i == n - 1) {
            mx_unmatched = a[n - 1];
        } else {
            mx_unmatched = 0; // All toys can be placed
        }
        cout << (mx_unmatched == 0 ? 1 : mx_unmatched) << endl;
    } else {
        // More than one toy cannot be placed in existing boxes
        cout << -1 << endl;
    }
    
    return 0;
}