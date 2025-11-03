#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    vector<int> prefix(2 * n + 1, 0);
    map<int, int> count;
    long long ans = 0;
    
    // Initialize: prefix sum of length 0 has value 0
    count[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        
        // When we have more than n elements, remove the contribution of the prefix that is now out of the sliding window
        if (i > n) {
            int old_prefix = prefix[i - n - 1];
            count[old_prefix]--;
        }
        
        // Add number of previous prefixes with same value (they form subarrays divisible by m)
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans << endl;
    return 0;
}