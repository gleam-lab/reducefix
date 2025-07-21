#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    
    // The minimum difference will be achieved by removing the smallest K elements or the largest K elements
    // This is because removing smaller elements increases the minimum value of B and removing larger elements decreases the maximum value of B
    int ans = min(a[n-k] - a[0], a[n-1] - a[k]);
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}