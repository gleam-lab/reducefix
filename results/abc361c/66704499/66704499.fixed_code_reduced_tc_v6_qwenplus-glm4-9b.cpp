#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    
    int left = 0, right = n - 1;
    int min_difference = INT_MAX;
    
    while (left + k <= n && right - k >= 0) {
        // Calculate current difference
        int current_diff = nums[right] - nums[left];
        min_difference = std::min(min_difference, current_diff);
        
        // Move left pointer to the right
        left++;
        // If we have removed too many elements from the left, move right pointer to the left
        if (left + k > n) {
            right--;
        }
    }
    
    std::cout << min_difference << std::endl;
    
    return 0;
}