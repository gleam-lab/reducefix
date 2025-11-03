#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> prefix(2 * n + 1);
    vector<int> count(m, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    long long ans = 0;
    
    // Calculate prefix sums modulo m
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    // Initialize: empty subarray has sum 0
    count[0] = 1;
    
    // Process first n prefix sums (positions 0 to n)
    for (int i = 1; i <= n; i++) {
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    // Slide window: remove contribution of position i-n, add position i
    for (int i = n + 1; i <= 2 * n; i++) {
        // Remove the prefix that is now out of range
        count[prefix[i - n]]--;
        
        // Count valid subarrays ending at position i
        ans += count[prefix[i]];
        
        // Add current prefix to count
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}