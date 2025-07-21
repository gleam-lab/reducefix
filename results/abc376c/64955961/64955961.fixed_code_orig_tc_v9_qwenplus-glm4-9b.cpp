#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    ll mx = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[j] > b[i]) {
                mx = max(mx, a[j]);
            }
        }
    }
    cout << mx << endl;
}

int main() {
    solve();
}