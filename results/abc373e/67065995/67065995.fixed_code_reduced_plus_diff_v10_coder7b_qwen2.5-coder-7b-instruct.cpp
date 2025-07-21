#include <bits/stdc++.h>
using namespace std;

long long binary_search(long long left, long long right, function<bool(long long)> check) {
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

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
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<long long> b = a;
    sort(b.begin(), b.end());
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        auto rid = upper_bound(b.begin(), b.end(), b[i] + k + 1) - b.begin();
        int lid = n - m - (i >= n - m ? 1 : 0);
        long long cnt = 0;
        if (rid > lid) cnt += (rid - lid) * (b[i] + k + 1) - (pref[rid] - pref[lid]);
        if (lid <= i && i < rid) cnt--;
        else cnt += k;
        if (cnt > k) ans[ord[i]] = -1;
        else ans[ord[i]] = cnt - k;
    }

    for (auto i : ans) cout << i << ' ';
    return 0;
}