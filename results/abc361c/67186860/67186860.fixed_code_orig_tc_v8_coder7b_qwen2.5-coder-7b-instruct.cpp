#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    // Read the input array
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    // Sort the array
    std::sort(arr.begin(), arr.end());
    
    // Initialize the result with the maximum possible difference
    long long result = LLONG_MAX;
    
    // Iterate through all possible starting points of the subarray
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values in the current subarray
        long long diff = arr[i + k - 1] - arr[i];
        
        // Update the result with the minimum difference found so far
        result = std::min(result, diff);
    }
    
    // Output the result
    std::cout << result << std::endl;
    
    return 0;
}