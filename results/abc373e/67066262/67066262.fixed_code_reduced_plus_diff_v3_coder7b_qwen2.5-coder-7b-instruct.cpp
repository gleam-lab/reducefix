#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        long long l = -1, r = k + 1;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            int rid = lower_bound(begin(a), end(a), a[ord[i]] + mid + 1) - begin(a);
            int lid = n - m - (i >= n - m ? 1 : 0);
            long long cnt = 0;
            if (rid > lid) cnt += (rid - lid) * (a[ord[i]] + mid + 1) - (pref[rid] - pref[lid]);
            if (lid <= i && i < rid) cnt--;
            else cnt += mid;
            if (cnt > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (l == k) ans[ord[i]] = -1;
        else ans[ord[i]] = r;
    }

    for (auto x : ans) cout << x << " ";
    return 0;
}