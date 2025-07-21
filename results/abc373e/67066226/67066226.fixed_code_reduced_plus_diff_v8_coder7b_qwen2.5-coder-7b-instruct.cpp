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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll l = 0, r = k + 1;
        while(l <= r) {
            ll mid = (l + r) / 2;
            int rid = upper_bound(pref.begin(), pref.end(), pref[n] - pref[i] + mid + 1) - pref.begin();
            int lid = n - m - (i >= n - m ? 1 : 0);
            ll cnt = 0;
            if(rid > lid) cnt += (rid - lid) * (pref[n] - pref[i] + mid + 1) - (pref[rid] - pref[lid]);
            if(lid <= i && i < rid) cnt--;
            else cnt += mid;
            if(cnt > k) {
                r = mid - 1;
            } else l = mid + 1;
        }
        if(l == k + 1) ans[ord[i]] = -1;
        else ans[ord[i]] = l;
    }

    for(auto x : ans) cout << x << " ";
    return 0;
}