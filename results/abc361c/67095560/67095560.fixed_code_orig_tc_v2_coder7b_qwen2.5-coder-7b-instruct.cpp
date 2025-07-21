#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    long long ans = LLONG_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, a[k + n - i - 1] - a[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}