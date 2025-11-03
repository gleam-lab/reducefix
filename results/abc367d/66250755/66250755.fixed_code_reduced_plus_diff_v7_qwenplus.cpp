#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    long long an = 0;
    map<int, int> t;
    vector<int> w(2 * n + 1, 0);
    
    t[0] = 1; // Important: prefix sum 0 appears once initially
    
    for (int i = 1; i < 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        if (i >= n) {
            // Remove the contribution from position i-n
            t[w[i-n]]--;
        }
        
        // Count how many previous prefix sums equal current one
        an += t[w[i]];
        
        // Add current prefix sum to map
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}