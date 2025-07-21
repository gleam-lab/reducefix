#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    // To remove the largest K elements, we can use the fact that
    // the largest K elements are at the end of the sorted array.
    // So, we remove the last K elements.
    for (int i = 0; i < k; i++) {
        nums.pop_back(); // This will remove the last element of the array.
    }

    // Now, after removing the largest K elements, the array is sorted again.
    int minVal = nums[0];
    int maxVal = nums[n - k - 1]; // The last element after removing K elements

    // The difference between the maximum and minimum values of B.
    cout << maxVal - minVal << endl;

    return 0;
}