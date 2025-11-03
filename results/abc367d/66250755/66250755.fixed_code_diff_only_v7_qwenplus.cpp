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
    
    t[0] = 1; // Empty prefix has sum 0
    
    for (int i = 1; i <= 2 * n; i++) {
        prefix = (prefix + a[i]) % m;
        an += t[prefix];
        t[prefix]++;
        
        // Remove the contribution of prefixes that are too far back
        if (i >= n) {
            int old_prefix = (prefix - a[i - n + 1] + m) % m;
            // We can't easily remove individual entries, so we need a different approach
        }
    }
    
    // Correct approach: use sliding window with proper removal
    t.assign(m, 0);
    an = 0;
    prefix = 0;
    
    // First, count all prefixes in the first n elements
    t[0] = 1;
    for (int i = 1; i <= n; i++) {
        prefix = (prefix + a[i]) % m;
        an += t[prefix];
        t[prefix]++;
    }
    
    // Now slide the window
    prefix = 0;
    t.assign(m, 0);
    t[0] = 1;
    
    // Calculate prefix sums for doubled array
    vector<int> w(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
    }
    
    // Use the fact that we want subarrays of length at most n
    an = 0;
    for (int i = 1; i <= 2 * n; i++) {
        // When we reach position i, we need to remove the prefix at position i-n-1
        if (i > n) {
            t[w[i - n - 1]]--;
        }
        
        an += t[w[i]];
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}