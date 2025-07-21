#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    int ans = INT_MAX;
    
    // For odd k, we need to consider two cases:
    // 1. Removing the last element of the sequence after the window
    // 2. Removing the first element of the sequence after the window
    if (k % 2 == 1) {
        // Case 1: Remove the last element of the sequence after the window
        for (int i = 0; i <= n - k; ++i) {
            int max_val = 0, min_val = INT_MAX;
            for (int j = 0; j < k - 1; ++j) {
                max_val = max(max_val, a[i + j]);
                min_val = min(min_val, a[i + j]);
            }
            max_val = max(max_val, a[i + k - 1]);
            ans = min(ans, max_val - min_val);
        }
        
        // Case 2: Remove the first element of the sequence after the window
        for (int i = 1; i < n - k + 1; ++i) {
            int max_val = 0, min_val = INT_MAX;
            for (int j = 0; j < k - 1; ++j) {
                max_val = max(max_val, a[i + j]);
                min_val = min(min_val, a[i + j]);
            }
            max_val = max(max_val, a[i + k - 1]);
            ans = min(ans, max_val - min_val);
        }
        
    } else {
        // For even k, we can simply remove symmetric elements from both ends
        for (int i = 0; i <= n - k; ++i) {
            int max_val = 0, min_val = INT_MAX;
            for (int j = 0; j < k / 2; ++j) {
                max_val = max(max_val, a[i + j]);
                min_val = min(min_val, a[i + j]);
            }
            max_val = max(max_val, a[i + k / 2]);
            ans = min(ans, max_val - min_val);
        }
    }
    
    cout << ans << endl;
    return 0;
}