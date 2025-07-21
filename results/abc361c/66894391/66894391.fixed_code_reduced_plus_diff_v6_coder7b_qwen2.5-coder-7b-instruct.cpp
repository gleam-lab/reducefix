#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    // Sort the array to easily access the smallest and largest elements
    std::sort(nums.begin(), nums.end());

    // The minimum possible value of the difference is achieved by:
    // - Keeping the first (n-k) elements which will be the smallest
    // - Keeping the last (n-k) elements which will be the largest
    // Thus, we take the difference between the (n-K)-th element and the K-th element
    std::cout << nums[n - k - 1] - nums[k] << std::endl;

    return 0;
}