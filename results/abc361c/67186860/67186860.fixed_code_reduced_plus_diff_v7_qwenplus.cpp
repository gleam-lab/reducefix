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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    if (keep == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Try all possible contiguous subarrays of length 'keep' in the sorted array
    // because the optimal remaining sequence will be a contiguous block in sorted order
    long long ans = 1e18;
    for (int i = 0; i + keep - 1 < n; i++) {
        ans = min(ans, (long long)a[i + keep - 1] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}