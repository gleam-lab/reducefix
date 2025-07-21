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

    // Sort the array to facilitate the sliding window technique
    std::sort(a.begin(), a.end());

    // We will track the minimum range of elements that can be removed
    double minRange = std::numeric_limits<double>::max();

    // The sliding window size is k
    for (int left = 0; left <= n - k; ++left) {
        // Calculate the range of the maximum and minimum elements that cannot be removed
        double maxVal = (left + k - 1 < n) ? a[left + k - 1] : a[n - 1];
        double minVal = (left > 0) ? a[left - 1] : a[0];

        // Update the minimum possible range
        minRange = std::min(minRange, maxVal - minVal);
    }

    // Print the minimum range found
    std::cout << minRange << std::endl;

    return 0;
}