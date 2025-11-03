#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1), w(2 * n + 1);
    map<int, int> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    t[0] = 1; // Important: empty prefix has sum 0
    long long an = 0;
    
    for (int i = 1; i < 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        // Count how many previous prefixes give same remainder
        an += t[w[i]];
        
        // Add current prefix to hash map
        t[w[i]]++;
        
        // Remove prefix that is now out of sliding window (more than n elements back)
        if (i >= n) {
            t[w[i - n]]--;
        }
    }
    
    cout << an;
    return 0;
}