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

    int ans = INT_MAX;

    for (int i = 0; i <= k; i++) {
        int max_val = nums[min(n-1, i + (n-k-1))];
        int min_val = nums[max(0, k-i)];
        ans = min(ans, max_val - min_val);
    }

    cout << ans << endl;

    return 0;
}