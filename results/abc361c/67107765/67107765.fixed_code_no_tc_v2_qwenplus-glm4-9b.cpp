#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int &num : nums) {
        cin >> num;
    }
    
    // Sort the array to easily find the min and max
    sort(nums.begin(), nums.end());
    
    // If we only need to remove one element
    if (k == 1) {
        cout << nums[n - 1] - nums[0] << endl;
        return 0;
    }
    
    // We need to find the minimum possible value of the maximum value in B minus
    // the minimum value in B after removing exactly K elements.
    
    // The best way to minimize the range is to remove the largest and smallest values
    // to get a smaller range, but we also need to consider the middle values because
    // removing them might result in a smaller range.
    
    // If K is even, we can remove elements symmetrically from both ends.
    // If K is odd, we need to remove one element from one end and then decide between
    // removing the next element from the same end or the other end.
    
    int ans = INT_MAX;
    
    // If K is even, consider removing pairs from both ends of the sorted array
    if (k % 2 == 0) {
        for (int i = 0; i < k / 2; ++i) {
            int max_val = nums[n - 1 - i] - nums[i];
            ans = min(ans, max_val);
        }
    } else { // If K is odd, consider removing one element from one end and then consider the next one
        for (int i = 0; i < k / 2; ++i) {
            int max_val1 = nums[n - 1 - i] - nums[i];
            int max_val2 = nums[n - 1 - i] - nums[i + 1];
            ans = min(ans, min(max_val1, max_val2));
        }
    }
    
    // Check the case where we remove all but one element from one end
    int max_val_tail = nums[n - 1] - nums[0];
    ans = min(ans, max_val_tail);
    
    cout << ans << endl;
    
    return 0;
}