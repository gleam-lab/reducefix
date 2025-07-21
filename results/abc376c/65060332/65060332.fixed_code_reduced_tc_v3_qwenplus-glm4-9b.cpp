#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N], c[N];

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    sort(c, c + n);
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    ll l = 0, r = n - 1, lo = -1, hi = -1;
    
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll i = 0, j = 0, box = 0;
        while (i < n) {
            if (b[j] >= c[mid] || j >= n - 1) {
                box++;
                j++;
            } else {
                i++;
            }
        }
        if (box == n) {
            lo = mid;
            hi = mid;
            l = mid + 1;
        } else {
            hi = mid;
            r = mid - 1;
        }
    }
    
    if (lo == -1) {
        cout << -1;
    } else {
        cout << c[lo];
    }
    
    return 0;
}