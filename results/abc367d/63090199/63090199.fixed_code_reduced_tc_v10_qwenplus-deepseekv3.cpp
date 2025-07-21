#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + nums[i]) % m;
    }
    
    int total_sum = prefix_sum[n];
    unordered_map<int, int> mod_count;
    long long count = 0;
    
    for (int i = 1; i <= n; ++i) {
        int current_mod = prefix_sum[i];
        int target_mod = (current_mod - total_sum + m) % m;
        count += mod_count[target_mod];
        mod_count[current_mod]++;
    }
    
    cout << count << endl;
    return 0;
}