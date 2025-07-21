#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // The minimum possible value of the difference between the maximum and minimum values of B
    // can be achieved by removing k smallest and k largest elements from A
    long long ans = LLONG_MAX;
    
    // Iterate over possible positions to split the array into two parts
    for (int i = 0; i <= k; ++i) {
        // Calculate the difference between the maximum and minimum values of the resulting array
        long long diff = a[min(n - 1, i + k)] - a[max(0, i)];
        ans = min(ans, diff);
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}