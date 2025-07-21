#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];
int main() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(ll i = 1; i < n; ++i) {
        cin >> b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n);
    
    ll x = 0;
    for(ll i = 1; i <= n; ++i) {
        if (a[i] < b[i-1]) {
            x = a[i]; // Find the first toy that can't fit in the existing boxes
            break;
        }
    }
    if (x > 0) {
        cout << x;
    } else {
        cout << a[n]; // If no toy requires a new box, the new box size is the size of the last toy
    }
    return 0;
}