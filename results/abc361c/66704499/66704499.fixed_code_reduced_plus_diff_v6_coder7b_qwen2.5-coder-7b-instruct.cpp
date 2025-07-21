#include <bits/stdc++.h>
using namespace std;

int nums[200000];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    // Calculate the difference between the largest and smallest possible sequences after removing K elements
    int ans = nums[n-1-k] - nums[k];
    
    cout << ans << endl;

    return 0;
}