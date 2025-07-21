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

    ll i = 0, j = 0, cnt = 0;
    ll max_unmatched = 0;
    while (i < n && j < n-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            max_unmatched = max(max_unmatched, a[i]);
            cnt++;
            i++;
        }
    }
    while (i < n) {
        max_unmatched = max(max_unmatched, a[i]);
        cnt++;
        i++;
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << max_unmatched << endl;
    }
}

int main() {
    solve();
    return 0;
}