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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = a[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll l = 0, r = k + 1;
        while(l <= r) {
            ll mid = (l + r) / 2;
            int rid = upper_bound(begin(a), begin(a) + n, a[ord[i]] + mid + 1) - begin(a);
            int lid = n - m - (i >= n - m ? 1 : 0);
            ll cnt = 0;
            if(rid > lid) cnt += (rid - lid) * (a[ord[i]] + mid + 1) - (pref[rid] - pref[lid]);
            if(lid <= i && i < rid) cnt--;
            else cnt += mid;
            if(cnt > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(l == k + 1) ans[ord[i]] = -1;
        else ans[ord[i]] = l;
    }

    for(auto x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}