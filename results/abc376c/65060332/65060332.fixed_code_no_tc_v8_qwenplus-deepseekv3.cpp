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
    
    vector<ll> unmatched;
    ll i = n - 1, j = n - 2; // Pointers for toys and boxes
    
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            i--;
            j--;
        } else {
            unmatched.push_back(a[i]);
            i--;
        }
    }
    while (i >= 0) {
        unmatched.push_back(a[i]);
        i--;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else {
        cout << 1 << endl; // All toys matched, x can be any size >= 1, smallest is 1
    }
    
    return 0;
}