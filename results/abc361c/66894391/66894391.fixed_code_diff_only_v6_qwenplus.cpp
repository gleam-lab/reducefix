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
    
    // We remove exactly K elements, leaving (n - k) elements
    // To minimize (max - min) of remaining elements,
    // we should consider removing some prefix and suffix elements
    // Try all possible combinations: remove i elements from left, (k-i) from right
    long long ans = 1e18;
    for (int i = 0; i <= k; i++) {
        int left_remove = i;
        int right_remove = k - i;
        
        // Remaining elements are from index [left_remove] to [n-1-right_remove]
        int l = left_remove;
        int r = n - 1 - right_remove;
        
        if (l <= r) {
            ans = min(ans, (long long)(a[r] - a[l]));
        }
    }
    
    cout << ans << endl;
    
    return 0;
}