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
    // The remaining sequence will have (n - k) elements
    // To minimize (max - min), we should consider contiguous segments of length (n-k)
    // in the sorted array
    
    int min_diff = a[n-1] - a[0]; // worst case: all elements remain
    
    // Try all possible contiguous segments of length (n-k)
    // by removing k elements from left and right ends
    for (int left_removed = 0; left_removed <= k; left_removed++) {
        int right_removed = k - left_removed;
        int remaining_left = left_removed;
        int remaining_right = n - 1 - right_removed;
        
        if (remaining_left <= remaining_right) {
            min_diff = min(min_diff, a[remaining_right] - a[remaining_left]);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}