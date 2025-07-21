#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // Sort the array
    sort(nums, nums + n);

    // The minimum possible value of the difference is achieved by removing the first K elements
    int result = nums[n - 1] - nums[K];

    cout << result << endl;

    return 0;
}