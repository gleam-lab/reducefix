#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[400005], prefix[400005];
unordered_map<long long, int> freq;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i]; // Create circular array
    }
    
    prefix[0] = 0;
    for(int i = 1; i <= 2*n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    long long res = 0;
    freq[0] = 1; // Initial prefix sum
    
    for(int i = 1; i <= 2*n; i++) {
        if(i > n) {
            // Remove the prefix sum that's out of current window
            long long old_prefix = prefix[i - n] % m;
            freq[old_prefix]--;
        }
        
        // Add current prefix sum's complement
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }
    
    cout << res;
    return 0;
}