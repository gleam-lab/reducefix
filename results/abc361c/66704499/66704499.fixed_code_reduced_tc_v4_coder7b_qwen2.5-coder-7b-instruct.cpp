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

    // Select the smallest K+1 elements and the largest K+1 elements
    int min_val = min(nums[k], nums[n-k-1]);
    int max_val = max(nums[k], nums[n-k-1]);

    cout << max_val - min_val << endl;

    return 0;
}