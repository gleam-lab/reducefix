#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    
    // Read and sort the array
    for (int &i : a) std::cin >> i;
    std::sort(a.begin(), a.end());
    
    // Initialize the answer with the worst possible case
    long long ans = a[n-1] - a[0];
    
    // Calculate the best possible answer
    // We use a sliding window approach to consider removing K elements at a time
    for (int i = 0; i <= k; ++i) {
        long long maxVal = 0, minVal = a[0];
        // Find the maximum in the window from the end
        for (int j = n - k; j < n; ++j) {
            maxVal = std::max(maxVal, a[j]);
        }
        // Find the minimum in the window from the start
        for (int j = i; j < i + k - 1; ++j) {
            minVal = std::min(minVal, a[j]);
        }
        ans = std::min(ans, maxVal - minVal);
    }
    
    std::cout << ans << std::endl;
    return 0;
}