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

    // Remove the smallest K elements and the largest K elements
    int result = nums[n - k] - nums[k];

    cout << result << endl;

    return 0;
}