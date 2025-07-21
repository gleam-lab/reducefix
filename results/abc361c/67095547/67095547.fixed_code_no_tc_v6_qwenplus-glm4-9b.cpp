#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the sequence
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the sequence to make it easier to find minimum and maximum
    sort(a.begin(), a.end());
    
    // Initialize the minimum difference to a large value
    long long min_diff = LLONG_MAX;
    
    // Iterate over all possible pairs of indices i, j to remove elements
    for (int i = 0; i <= n - k; ++i) {
        int j = i + k - 1; // j will be the last index after removing k elements starting from i
        
        // Calculate the minimum and maximum of the remaining elements
        long long min_val = a[i];
        long long max_val = a[j];
        
        // Calculate the difference and update the minimum difference found
        min_diff = min(min_diff, max_val - min_val);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}