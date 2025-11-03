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
    // The optimal strategy is to remove some number of elements from the left and right ends
    // Try all possible combinations: remove i elements from the left and (k-i) from the right
    int min_diff = INT_MAX;
    int remaining = n - k;
    
    for (int i = 0; i <= k; i++) {
        int left_remove = i;
        int right_remove = k - i;
        
        // Check if we have enough elements to remove
        if (left_remove + right_remove > n || left_remove > n || right_remove > n) {
            continue;
        }
        
        // After removing 'left_remove' from left and 'right_remove' from right
        // The remaining array is from index [left_remove] to [n-1-right_remove]
        int left_idx = left_remove;
        int right_idx = n - 1 - right_remove;
        
        // Make sure we have at least one element left
        if (left_idx <= right_idx) {
            int diff = a[right_idx] - a[left_idx];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    return 0;
}