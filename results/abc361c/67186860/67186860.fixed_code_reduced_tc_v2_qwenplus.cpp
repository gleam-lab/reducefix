#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    long long ans = 1e18;
    // Try removing k elements: left l elements and right r elements, where l + r = k
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        if (l + r > n) continue;
        if (n - l - r <= 0) continue;
        long long min_val = a[l];
        long long max_val = a[n - 1 - r];
        ans = min(ans, max_val - min_val);
    }
    
    cout << ans << endl;
    return 0;
}