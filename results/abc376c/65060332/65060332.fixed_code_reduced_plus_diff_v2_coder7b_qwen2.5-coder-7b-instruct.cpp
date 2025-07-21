#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, cnt = 0, mx = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    ll l = 1, r = 1;
    while (l <= n) {
        if (r > n - 1 || b[r] < a[l]) {
            cout << -1;
            return 0;
        } else {
            mx = max(mx, a[l]);
            l++;
            r++;
        }
    }

    cout << mx;
    return 0;
}