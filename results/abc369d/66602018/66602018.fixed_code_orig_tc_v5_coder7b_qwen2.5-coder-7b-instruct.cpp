#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    // Using vector to store the numbers instead of array for dynamic size
    std::vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    // Sort the numbers to maximize the sum of even-indexed elements minus odd-indexed elements
    std::sort(nums.begin(), nums.end());
    
    long long result = 0;
    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            result += nums[i];
        } else {
            result -= nums[i];
        }
    }
    
    std::cout << result << std::endl;
    return 0;
}