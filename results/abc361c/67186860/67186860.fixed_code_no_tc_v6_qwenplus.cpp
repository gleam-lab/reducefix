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
    
    // We need to remove exactly K elements
    // The remaining sequence will be a contiguous subarray of the sorted array
    // because we want to minimize (max - min)
    // So try all possible ways: remove x from left and (k-x) from right
    int ans = INT_MAX;
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        
        // Check if this removal is valid
        if (left_removed + right_removed > n) continue;
        if (n - left_removed - right_removed == 0) continue;
        
        int min_val = a[left_removed];
        int max_val = a[n - 1 - right_removed];
        ans = min(ans, max_val - min_val);
    }
    
    cout << ans << endl;
    return 0;
}