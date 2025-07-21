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
    
    ll i = 0, j = 0;
    ll cnt = 0;
    ll last_unmatched = -1;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            cnt++;
            last_unmatched = a[i];
            i++;
        }
    }
    while (i < n) {
        cnt++;
        last_unmatched = a[i];
        i++;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (cnt == 0) {
            cout << a.back() << endl;
        } else {
            cout << last_unmatched << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}