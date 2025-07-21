#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> b(a);
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; i++) {
        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll rid = upper_bound(all(b), b[i] + mid) - b.begin();
            ll lid = max(0LL, n - m - (i >= n - m ? 1 : 0));
            ll cnt = 0;
            if (rid > lid) cnt += (rid - lid) * (b[i] + mid) - (pref[rid] - pref[lid]);
            if (lid <= i && i < rid) cnt++;
            else cnt += mid;
            if (cnt > k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l > k) ans[ord[i]] = -1;
        else ans[ord[i]] = l;
    }
    for (auto i : ans) cout << i << ' ';
}