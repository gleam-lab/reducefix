#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Compute prefix sums: prefixsum[i] = sum of nums[0] to nums[i-1]
    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = (prefixsum[i] + nums[i]) % m;
    }

    long long count = 0;
    unordered_map<int, int> mod_count;
    
    // Every prefix sum mod m, including 0 at index 0
    for (int i = 0; i <= n; i++) {
        int mod = prefixsum[i] % m;
        if (mod < 0) mod += m; // Ensure non-negative modulo
        count += mod_count[mod];
        mod_count[mod]++;
    }

    cout << count << endl;
    return 0;
}