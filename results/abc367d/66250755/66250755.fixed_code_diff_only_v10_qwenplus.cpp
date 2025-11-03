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
    
    // Initialize: prefix[0] = 0
    prefix[0] = 0;
    count[0] = 1;  // Empty prefix has sum 0
    
    for (int i = 1; i < 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        
        // When we have more than n elements, remove the contribution of prefixes that are too far back
        if (i > n) {
            count[prefix[i - n - 1]]--;
        }
        
        // Add number of valid prefixes that can form subarray ending at position i with length <= n
        if (i >= n) {
            ans += count[prefix[i]];
        } else {
            ans += count[prefix[i]];
        }
        
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}