#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> t(m, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    long long an = 0;
    int prefix = 0;
    
    // Initialize: empty prefix has sum 0
    t[0] = 1;
    
    for (int i = 1; i < 2 * n; i++) {
        prefix = (prefix + a[i]) % m;
        
        // Remove the contribution of prefixes that are too far back (> n length)
        if (i > n) {
            int old_prefix = (prefix - a[i - n] + m) % m;
            // We need to find the prefix at position i-n-1
            int pos = i - n - 1;
            if (pos >= 0) {
                int p = 0;
                for (int j = 1; j <= pos; j++) {
                    p = (p + a[j]) % m;
                }
                t[p]--;
            }
        }
        
        // Add valid subarrays ending at position i with length <= n
        an += t[prefix];
        
        // Add current prefix to hash table
        t[prefix]++;
    }
    
    cout << an;
    return 0;
}