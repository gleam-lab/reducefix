#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> t(m, 0);
    long long an = 0;
    int prefix = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    // Initialize: empty prefix has sum 0
    t[0] = 1;
    
    for (int i = 1; i < 2 * n; i++) {
        prefix = (prefix + a[i]) % m;
        
        // Count how many previous prefixes give a valid subarray of length <= n
        an += t[prefix];
        
        // Add current prefix to hash table
        t[prefix]++;
        
        // Remove prefix that is now too far (more than n elements away)
        if (i >= n) {
            int old_prefix = (prefix - a[i - n] + m) % m;
            // We need to remove the prefix at position i-n
            // But we don't have it directly, so we track removals differently
            
            // Instead, we'll use a different approach: only consider prefixes within valid range
            // We remove the prefix sum that ended exactly n positions ago
            int pos_to_remove = i - n;
            if (pos_to_remove >= 1) {
                int prefix_to_remove = 0;
                // Recalculate prefix sum at position pos_to_remove
                prefix_to_remove = 0;
                for (int j = 1; j <= pos_to_remove; j++) {
                    prefix_to_remove = (prefix_to_remove + a[j]) % m;
                }
                t[prefix_to_remove]--;
            }
        }
    }
    
    // The above approach is inefficient. Let's rewrite with proper sliding window:
    
    t.assign(m, 0);
    an = 0;
    prefix = 0;
    
    t[0] = 1; // empty prefix
    
    // We'll maintain a deque or just recalculate properly
    vector<int> prefix_sum(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        prefix_sum[i] = (prefix_sum[i-1] + a[i]) % m;
    }
    
    t[0] = 1; // prefix_sum[0] = 0
    
    for (int i = 1; i <= 2 * n; i++) {
        // Remove prefixes that are more than n positions behind
        while (i > n) {
            t[prefix_sum[i - n - 1]]--;
            break; // just remove one per iteration
        }
        
        an += t[prefix_sum[i]];
        t[prefix_sum[i]]++;
    }
    
    cout << an;
    return 0;
}