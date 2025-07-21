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
    ll required_x = 0;
    ll i = 0, j = 0;
    
    while (i < n && j < n - 1) {
        if (b[j] >= a[i]) {
            i++;
            j++;
        } else {
            cnt++;
            required_x = a[i];
            i++;
        }
    }
    
    while (i < n) {
        cnt++;
        required_x = a[i];
        i++;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (cnt == 0) {
            // All toys fit in existing boxes, but we need to use all boxes (including the new one)
            // So the new box can be any size >= the smallest toy not placed in any existing box
            // But since all toys are placed, the new box can be size 1 (or any value)
            // However, the problem says we must place each toy in a box, and the new box must be used.
            // So we need to ensure that the new box is used, meaning one toy must be placed in it.
            // Thus, find the smallest toy that can be placed in the new box.
            // The existing boxes are all used, so the new box must contain one toy.
            // The minimal x is the smallest toy's size.
            required_x = a[0];
        }
        cout << required_x << endl;
    }
    
    return 0;
}