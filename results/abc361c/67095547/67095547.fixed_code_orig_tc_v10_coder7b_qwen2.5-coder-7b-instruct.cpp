#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long min_difference(vector<long long>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long min_diff = LLONG_MAX;
    
    // Consider removing k smallest and largest elements one by one
    for (int i = 0; i <= k; ++i) {
        long long diff = nums[min(k, n - 1) - i] - nums[i];
        min_diff = min(min_diff, diff);
    }
    
    return min_diff;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << min_difference(nums, k) << endl;
    
    return 0;
}