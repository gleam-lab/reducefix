#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int lid = n - m - (i >= n - m ? 1 : 0);
        if (lid < 0) lid = 0;
        int rid = upper_bound(begin(a) + i + 1, end(a), a[i]) - begin(a);
        if (rid < 0) rid = 0;

        ll cnt = 0;
        if (rid > lid) {
            cnt += (rid - lid) * (a[i] + 1) - (pref[rid] - pref[lid]);
        }
        if (lid <= i && i < rid) {
            --cnt;
        } else {
            ++cnt;
        }

        if (cnt <= k) {
            ans[ord[i]] = 0;
        } else {
            ans[ord[i]] = cnt - k;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}