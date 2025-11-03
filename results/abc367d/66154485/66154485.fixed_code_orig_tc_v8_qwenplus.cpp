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

    // Count frequency of prefix sums modulo m
    map<int, long long> count;
    count[0] = 1; // Empty prefix has sum 0
    
    long long ans = 0;
    int prefix_sum = 0;
    
    for (int i = 0; i < n; i++) {
        prefix_sum = (prefix_sum + arr[i]) % m;
        if (prefix_sum < 0) prefix_sum += m; // Handle negative modulo
        
        // If we've seen this remainder before, it means there are subarrays ending at position i with sum divisible by m
        ans += count[prefix_sum];
        
        // Update the frequency count
        count[prefix_sum]++;
    }
    
    cout << ans;
    return 0;
}