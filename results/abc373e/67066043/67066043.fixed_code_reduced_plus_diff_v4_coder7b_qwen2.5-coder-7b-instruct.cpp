#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], i};
    }

    sort(p.rbegin(), p.rend());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + p[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int id = p[i].second;
        ll need = 0;
        if (i < n - m) {
            ll remaining = k - (pref[n] - pref[i + 1]);
            need = (p[m - 1].first - p[i].first) * (n - m - i) + remaining;
        } else {
            need = (p[n - 1].first - p[i].first) * (n - i);
        }
        if (need <= k) {
            ans[id] = need;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}