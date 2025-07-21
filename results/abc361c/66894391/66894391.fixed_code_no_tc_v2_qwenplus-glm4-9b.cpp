#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // Sort the array
    sort(nums.begin(), nums.end());

    // We need to remove exactly K elements
    // If we remove all from one end to the other, we get the maximum possible difference
    // So we can just remove the first k smallest or the last k largest elements
    // The minimum possible value of the difference will be between the smallest of the remaining elements
    // and the largest of the remaining elements after removal of K elements

    // We can simply remove the first k elements to get the answer
    // because removing k smallest elements will maximize the difference between
    // the smallest remaining element and the largest remaining element
    int min_value = nums[k];
    int max_value = nums[n - 1];

    cout << max_value - min_value << endl;

    return 0;
}