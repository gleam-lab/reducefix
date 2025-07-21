#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Sort the array to facilitate the selection of K elements to remove
    sort(nums.begin(), nums.end());
    
    // The best candidates to maximize min(B) and minimize max(B) after removing K elements
    // are the smallest and largest values that would remain in the sequence.
    // Since we want to minimize the range of B, we should remove elements that are farthest from each other.
    
    // The first element after removing k elements will be nums[k]
    int min_b = nums[k]; // Minimum of the remaining sequence after removal
    int max_b = nums[n - k - 1]; // Maximum of the remaining sequence after removal
    
    // The answer is the difference between the maximum and minimum of the remaining elements
    cout << max_b - min_b << endl;
    
    return 0;
}