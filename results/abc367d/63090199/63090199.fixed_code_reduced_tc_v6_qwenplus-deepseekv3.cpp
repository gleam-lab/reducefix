#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
    vector<int> mod_counts(m, 0);
    mod_counts[0] = 1;
    int current_mod = 0;
    long long count = 0;
    
    for (int num : nums) {
        current_mod = (current_mod + num) % m;
        if (current_mod < 0) current_mod += m;
        count += mod_counts[current_mod];
        mod_counts[current_mod]++;
    }
    
    cout << count << endl;
    return 0;
}