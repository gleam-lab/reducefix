#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
    
    ll cnt = 0;
    ll required_x = 0;
    ll i = n - 1, j = n - 2;
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            --i;
            --j;
        } else {
            required_x = a[i];
            ++cnt;
            --i;
        }
    }
    while (i >= 0) {
        required_x = a[i];
        ++cnt;
        --i;
    }
    if (cnt > 1) {
        cout << -1 << '\n';
    } else {
        cout << required_x << '\n';
    }
    return 0;
}