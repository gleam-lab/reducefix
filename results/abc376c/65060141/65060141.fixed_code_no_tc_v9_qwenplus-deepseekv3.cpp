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
    
    ll cnt = 0;
    ll mx_unmatched = 0;
    ll j = n - 2; // index for boxes
    for (ll i = n - 1; i >= 0; i--) {
        if (j >= 0 && b[j] >= a[i]) {
            j--;
        } else {
            cnt++;
            if (cnt > 1) {
                cout << -1 << endl;
                return 0;
            }
            mx_unmatched = a[i];
        }
    }
    
    if (cnt == 0) {
        // All toys fit in existing boxes; no new box needed, but we need to place one toy in new box
        // So, x can be the smallest toy's size
        cout << 1 << endl;
    } else {
        cout << mx_unmatched << endl;
    }
    
    return 0;
}