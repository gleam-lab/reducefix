#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll i = n - 1, j = n - 2;
    ll cnt = 0;
    ll x = 0;
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            i--;
            j--;
        } else {
            x = a[i];
            i--;
            cnt++;
        }
    }
    while (i >= 0) {
        x = a[i];
        i--;
        cnt++;
    }
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    solve();
    return 0;
}