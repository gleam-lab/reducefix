#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + nums[i]) % m;
    }
    
    unordered_map<int, int> mod_count;
    mod_count[0] = 1; // To account for prefix_sum[0]
    long long count = 0;
    
    for (int i = 1; i <= n; i++) {
        int mod = prefix_sum[i];
        count += mod_count[mod];
        mod_count[mod]++;
    }
    
    cout << count << endl;
    return 0;
}