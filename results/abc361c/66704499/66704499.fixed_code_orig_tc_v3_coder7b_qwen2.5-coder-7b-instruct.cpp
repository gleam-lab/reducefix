#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    long long result = LLONG_MAX;
    for (int i = 0; i <= n - k; i++) {
        result = min(result, nums[i + k - 1] - nums[i]);
    }
    
    cout << result << endl;
    
    return 0;
}