#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int mini = a[k] - a[0]; // Removing the smallest k elements
    int maxi = a[n-1] - a[n-k-1]; // Removing the largest k elements

    cout << min(mini, maxi) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}