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

    for(int i=0;i<=n-k;i++){
        ans = min(ans, nums[i+k-1]-nums[i]);
    }

    cout << ans << endl;

    return 0;
}