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
    for (ll i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n - 1);
    
    ll cnt = 0;
    ll mx = 0;
    ll i = n - 1;
    ll j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            --j;
            --i;
        } else {
            mx = max(mx, a[i]);
            ++cnt;
            --i;
        }
    }
    while (i >= 0) {
        mx = max(mx, a[i]);
        ++cnt;
        --i;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << mx << endl;
    }
    return 0;
}