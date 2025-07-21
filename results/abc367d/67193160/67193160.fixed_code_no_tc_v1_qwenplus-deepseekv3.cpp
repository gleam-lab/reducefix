#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[2*N], prefix[2*N], freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];  // Make it circular by doubling
    }
    
    prefix[0] = 0;
    freq[0] = 1;  // Initialize for prefix[0] mod m == 0
    long long res = 0;
    
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
        if(i > n) {
            // Remove the prefix sum that's now out of window
            long long prev_mod = prefix[i-n-1] % m;
            if(prev_mod < 0) prev_mod += m;  // Handle negative mod
            freq[prev_mod]--;
        }
        
        long long curr_mod = prefix[i] % m;
        if(curr_mod < 0) curr_mod += m;  // Handle negative mod
        
        res += freq[curr_mod];
        if(i < n) {  // Only count frequencies for first n elements
            freq[curr_mod]++;
        }
    }
    
    cout << res << "\n";
    return 0;
}