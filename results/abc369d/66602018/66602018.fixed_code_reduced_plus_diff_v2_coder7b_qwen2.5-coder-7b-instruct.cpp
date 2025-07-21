#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    // If there's only one number, it is the answer
    if(n == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    
    // Sort the numbers to facilitate the calculation of the maximum sum
    sort(nums.begin(), nums.end());
    
    // The maximum sum can be obtained by taking the largest two numbers and adding them
    // This is because the problem asks for the maximum sum of two distinct numbers
    long long max_sum = nums[n-1] + nums[n-2];
    
    cout << max_sum << endl;
    
    return 0;
}