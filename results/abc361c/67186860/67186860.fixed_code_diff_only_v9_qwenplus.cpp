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
    
    // We need to remove exactly K elements, leaving N-K elements
    // To minimize max - min of remaining elements,
    // we should consider removing some prefix and suffix elements
    // Try all possible ways: remove i elements from left and (k-i) from right
    int ans = INT_MAX;
    int remaining = n - k;
    
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        
        // If we remove 'left_removed' from left and 'right_removed' from right
        // then the remaining array is from index [left_removed] to [n-1-right_removed]
        int left_idx = left_removed;
        int right_idx = n - 1 - right_removed;
        
        // Check if valid range
        if (left_idx <= right_idx) {
            ans = min(ans, a[right_idx] - a[left_idx]);
        }
    }
    
    cout << ans << endl;
    return 0;
}