#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Sort the vector a.
    std::sort(a.begin(), a.end());
    
    // Calculate the minimum possible value of the maximum value of B minus the minimum value of B
    // after removing exactly K elements from the sorted sequence.
    int max_diff = 0;
    for (int i = 0; i <= k; ++i) { // We consider scenarios of removing up to K elements
        int max_element = a[n - k + i]; // Max element after removing i elements
        int min_element = a[i]; // Min element after removing i elements
        int diff = max_element - min_element;
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    
    // Output the maximum difference found
    std::cout << max_diff << std::endl;
    return 0;
}