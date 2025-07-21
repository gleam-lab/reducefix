#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N], b[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    
    sort(a, a + n);
    sort(b, b + n - 1);
    
    ll i = 0, j = 0;
    ll cnt = 0;
    ll mx = 0;
    
    while (i < n && j < n-1) {
        if (b[j] >= a[i]) {
            i++;
            j++;
        } else {
            cnt++;
            mx = max(mx, a[i]);
            i++;
        }
    }
    
    while (i < n) {
        cnt++;
        mx = max(mx, a[i]);
        i++;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (cnt == 0) {
            // All toys placed, need a box of size at least the smallest toy not placed (but all are placed, so invalid?)
            // Actually, if all toys are placed, then the new box can be of size 1 (or any size, but it's unused)
            cout << 1 << endl;
        } else {
            cout << mx << endl;
        }
    }
    
    return 0;
}