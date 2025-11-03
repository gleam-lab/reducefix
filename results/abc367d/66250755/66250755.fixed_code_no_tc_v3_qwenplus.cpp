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
    
    long long an = 0;
    t[0] = 1; // Important: empty prefix has sum 0
    
    for (int i = 1; i < 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        // Count how many previous prefixes with same remainder are within valid range
        if (i >= n) {
            // Remove the prefix that is now out of range (exactly n positions back)
            t[w[i - n]]--;
        }
        
        // Add count of prefixes with same remainder in current window
        an += t[w[i]];
        
        // Add current prefix to the map
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}