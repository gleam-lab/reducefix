#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the array to facilitate the calculation of the maximum and minimum values
    sort(a.begin(), a.end());
    
    // Initialize the maximum and minimum values after removing k elements
    int max_val = INT_MIN, min_val = INT_MAX;
    int window_start = 0;
    
    // Slide the window of size k over the sorted array to find the minimum possible range
    for (int window_end = 0; window_end < n; window_end++) {
        // Expand the window
        max_val = max(max_val, a[window_end]);
        
        // If the window size is k, try to shrink it from the left
        if (window_end - window_start + 1 > k) {
            min_val = min(min_val, a[window_start]);
            window_start++;
        }
    }
    
    // If no valid window of size k could be formed, return 0 (although the problem guarantees k < n)
    if (window_start == 0) {
        cout << 0 << endl;
    } else {
        // The minimum possible value of the maximum minus the minimum of the remaining elements
        cout << max_val - min_val << endl;
    }
    
    return 0;
}