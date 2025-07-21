#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    const int MAXN = 400005;
    long long a[MAXN * 2], prefix[MAXN * 2];
    map<int, int> countMap;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];  // Duplicate array for circular property
    }
    
    // Compute prefix sums modulo m
    prefix[0] = 0;
    for (int i = 1; i < 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    
    long long result = 0;
    countMap[0] = 1;  // Initialize with 0 to count subarrays starting from index 0
    
    for (int i = 1; i < 2 * n; ++i) {
        // Only consider subarrays of length <= n
        if (i > n) {
            countMap[prefix[i - n]]--;
        }
        
        // Count valid subarrays ending at i
        result += countMap[prefix[i]];
        
        // Add current prefix to the map for future subarrays
        countMap[prefix[i]]++;
    }
    
    cout << result << "\n";
    return 0;
}