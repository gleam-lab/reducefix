#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_castio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        long long l = 0, r = k + 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            int rid = upper_bound(a.begin(), a.end(), a[i] + mid + 1) - a.begin();
            int lid = n - m - (i >= n - m ? 1 : 0);
            long long cnt = 0;
            if (rid > lid) cnt += (rid - lid) * (a[i] + mid + 1) - (pref[rid] - pref[lid]);
            if (lid <= i && i < rid) cnt--;
            else cnt += mid;
            if (cnt > k) {
                r = mid - 1;
            } else l = mid + 1;
        }
        if (l == k + 1) ans[ord[i]] = -1;
        else ans[ord[i]] = l;
    }

    for (auto x : ans) cout << x << " ";
    return 0;
}