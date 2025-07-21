#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Initialize the minimum difference to a large number
    int min_diff = INT_MAX;
    
    // Iterate through all possible starting points for the subarray
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values in the current subarray
        int diff = a[i + k - 1] - a[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }
    
    // Print the result
    cout << min_diff << endl;
    
    return 0;
}