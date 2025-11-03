#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    // For each starting position
    for (int start = 0; start < n; start++) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1; // Empty prefix has sum 0
        long long current_sum = 0;
        
        // Extend the subarray from this start position
        for (int len = 1; len < n; len++) {
            int idx = (start + len) % n;
            current_sum += arr[idx];
            int mod_sum = ((current_sum % m) + m) % m; // Handle negative
            
            // If we've seen this modulo before, it means there's a subarray with sum divisible by m
            if (prefix_count.find(mod_sum) != prefix_count.end()) {
                ans += prefix_count[mod_sum];
            }
            
            prefix_count[mod_sum]++;
        }
    }
    
    cout << ans;
    return 0;
}