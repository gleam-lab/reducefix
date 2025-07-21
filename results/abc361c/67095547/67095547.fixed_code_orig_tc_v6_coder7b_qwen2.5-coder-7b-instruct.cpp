#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array
    sort(a.begin(), a.end());

    // The minimum difference will be between the maximum and minimum elements after removing k elements
    // We need to consider two scenarios:
    // 1. Remove k smallest elements
    // 2. Remove k largest elements
    int ans = min(a[n-k-1] - a[0], a[n-1] - a[k]);

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while(T--) {
        solve();
    }

    return 0;
}