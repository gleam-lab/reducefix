#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll i = n - 1, j = n - 2;
    ll cnt = 0;
    ll candidate = -1;
    
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            --i;
            --j;
        } else {
            if (cnt == 0) {
                candidate = a[i];
                ++cnt;
                --i;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i >= 0) {
        if (cnt == 0) {
            candidate = a[i];
            ++cnt;
            --i;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (cnt == 1) {
        cout << candidate << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}