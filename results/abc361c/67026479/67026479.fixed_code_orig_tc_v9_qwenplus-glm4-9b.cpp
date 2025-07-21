#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    // Step 1: Compute prefix minimum array
    vector<int> prefix_min(n);
    prefix_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], a[i]);
    }
    
    // Step 2: Find the minimum possible difference
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        // Remove the smallest i elements
        int min_b = prefix_min[k - 1]; // Minimum of the remaining elements
        int max_b = a[n - 1 - i]; // Maximum of the remaining elements
        
        // Calculate the difference
        min_diff = min(min_diff, max_b - min_b);
    }
    
    // Output the result
    cout << min_diff << endl;
    return 0;
}