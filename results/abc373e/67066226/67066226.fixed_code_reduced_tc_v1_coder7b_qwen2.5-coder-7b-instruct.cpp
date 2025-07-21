#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = a[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        if(i >= n - m) {
            ans[ord[i]] = 0;
            continue;
        }

        ll x = k - pref[n - m];
        if(x < 0) {
            ans[ord[i]] = -1;
            continue;
        }

        ll y = a[ord[n - m]];
        ll z = a[ord[n - m - 1]];

        if(y + x < z) {
            ans[ord[i]] = -1;
            continue;
        }

        ans[ord[i]] = x - (y - z);
    }

    for(auto i : ans) cout << i << ' ';
    
    return 0;
}