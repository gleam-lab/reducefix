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

    vector<pair<ll, int>> v(n);
    for(int i = 0; i < n; i++) v[i] = {a[i], i};

    sort(v.rbegin(), v.rend());

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i].first;
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll need = 0;
        for(int j = 0; j < m - 1; j++) {
            need += v[j].first;
        }
        need += v[m - 1].first - 1;
        if(k >= need) {
            ans[v[i].second] = 0;
        } else {
            ans[v[i].second] = -1;
        }
    }

    for(auto x : ans) cout << x << " ";

    return 0;
}