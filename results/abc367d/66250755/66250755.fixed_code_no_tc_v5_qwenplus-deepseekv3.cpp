#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2*n + 1);
    vector<int> w(2*n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    for(int i = 1; i <= 2*n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
    }
    
    unordered_map<int, int> freq;
    freq[0] = 1;  // Initialize with sum 0 at position 0
    long long ans = 0;
    
    for(int i = 1; i <= 2*n; i++) {
        if(i > n) {
            int prev_sum = w[i - n];
            freq[prev_sum]--;
        }
        
        ans += freq[w[i]];
        freq[w[i]]++;
    }
    
    cout << ans;
    return 0;
}