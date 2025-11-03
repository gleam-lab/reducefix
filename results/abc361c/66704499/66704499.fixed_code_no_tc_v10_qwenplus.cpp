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
    
    // We need to remove exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int min_diff = a[keep - 1] - a[0]; // Initial case: remove last k elements
    
    // Try all possible contiguous subarrays of length (n-k)
    // We can remove some elements from left and some from right
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