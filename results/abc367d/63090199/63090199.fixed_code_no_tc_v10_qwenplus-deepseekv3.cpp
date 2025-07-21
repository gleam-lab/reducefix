#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    long long total_sum = prefix[n];
    long long count = 0;
    unordered_map<long long, long long> mod_counts;
    mod_counts[0] = 1; // To account for subarrays starting at index 0
    
    for (int i = 1; i <= n; ++i) {
        long long mod = (prefix[i] % m + m) % m;
        count += mod_counts[mod];
        mod_counts[mod]++;
    }
    
    cout << count << endl;
    return 0;
}