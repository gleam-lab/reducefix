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
    // The remaining sequence will have n-k elements
    // To minimize max - min, we should consider removing elements from both ends
    // Try all possible ways: remove i elements from left and (k-i) elements from right
    int ans = INT_MAX;
    int remaining = n - k;
    
    for (int i = 0; i <= k; i++) {
        int left_remove = i;
        int right_remove = k - i;
        
        // Check if this removal is valid
        if (left_remove + right_remove <= n && remaining >= 1) {
            int left_idx = left_remove;
            int right_idx = n - 1 - right_remove;
            
            if (left_idx <= right_idx) {
                ans = min(ans, a[right_idx] - a[left_idx]);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}