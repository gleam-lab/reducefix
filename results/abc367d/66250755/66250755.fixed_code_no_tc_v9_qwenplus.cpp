#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> prefixSum(2 * n + 1, 0);
    vector<int> count(m, 0);
    long long ans = 0;
    
    // Read input and create doubled array for circular handling
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    // Compute prefix sums modulo m
    for (int i = 1; i <= 2 * n; i++) {
        prefixSum[i] = (prefixSum[i-1] + a[i]) % m;
    }
    
    // Initialize: empty subarray has sum 0
    count[0] = 1;
    
    // Process first n prefix sums (for positions 1 to n)
    for (int i = 1; i <= n; i++) {
        ans += count[prefixSum[i]];
        count[prefixSum[i]]++;
    }
    
    // Process remaining positions (n+1 to 2n), sliding window
    for (int i = n + 1; i <= 2 * n; i++) {
        // Remove the contribution of prefix that is now out of range
        count[prefixSum[i - n]]--;
        
        // Add valid subarrays ending at position i
        ans += count[prefixSum[i]];
        
        // Add current prefix to count
        count[prefixSum[i]]++;
    }
    
    cout << ans;
    return 0;
}