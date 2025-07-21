#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the elements of the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to easily find the minimum and maximum of any subarray
    sort(a.begin(), a.end());
    
    // If k == 0, no elements are removed, so the answer is 0
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Initialize the result to a large value
    long long res = LLONG_MAX;
    
    // We need to consider all subarrays of length n - k
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the max and min of the current subarray
        long long current_max = a[i + k - 1];
        long long current_min = a[i];
        long long diff = current_max - current_min;
        
        // Update the minimum difference found so far
        res = min(res, diff);
    }
    
    // Output the result
    cout << res << endl;
    
    return 0;
}