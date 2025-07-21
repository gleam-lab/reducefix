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

    int min_diff = INT_MAX;

    for (int i = 0; i <= n - k; i++){
        int current_diff = nums[i + k - 1] - nums[i];
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;

    return 0;
}