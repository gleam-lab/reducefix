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
    vector<int> w(2 * n + 1, 0);
    
    // Calculate prefix sums modulo m
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
    }
    
    // Count empty subarray at position 0
    t[0] = 1;
    
    // Process each position from 1 to 2*n
    for (int i = 1; i <= 2 * n; i++) {
        // For positions beyond n, remove the contribution from position i-n-1
        if (i > n) {
            t[w[i - n - 1]]--;
        }
        
        // Count how many previous prefix sums equal current one (within window of size n)
        an += t[w[i]];
        
        // Add current prefix sum to the frequency table
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}