#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int min_diff = LLONG_MAX;
    for (int i = 0; i + (n - k) - 1 < n; ++i) {
        min_diff = min(min_diff, a[i + (n - k) - 1] - a[i]);
    }
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}