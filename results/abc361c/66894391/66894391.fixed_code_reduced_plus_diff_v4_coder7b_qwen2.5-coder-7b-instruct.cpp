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

    std::sort(nums.begin(), nums.end());

    int result = nums[n-1] - nums[k];

    std::cout << result << std::endl;

    return 0;
}