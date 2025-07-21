#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    // Calculate the difference between the largest and smallest elements after removing k elements
    int mini = a[k] - a[0];

    // Calculate the difference between the largest and smallest elements after removing k elements from the end
    int maxi = a[n-k-1] - a[k];

    // The minimum possible value of the maximum element minus the minimum element of B
    cout << min(mini, maxi) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}