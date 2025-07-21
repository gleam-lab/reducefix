#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll unmatched = 0;
    ll x = -1;
    ll i = 0, j = 0;
    while (i < n && j < n-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = a[i];
                unmatched++;
                i++;
            } else {
                unmatched++;
                i++;
            }
        }
    }
    while (i < n) {
        if (x == -1) {
            x = a[i];
            unmatched++;
        } else {
            unmatched++;
        }
        i++;
    }
    
    if (unmatched > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    solve();
    return 0;
}