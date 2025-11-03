#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[2*N];
long long ans;
map<int,int> cnt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    cnt[0] = 1; // prefix sum 0 appears once at the beginning
    long long prefix = 0;
    
    for(int i = 1; i < 2*n; i++) {
        prefix = (prefix + a[i]) % m;
        if(prefix < 0) prefix += m; // Ensure non-negative modulo
        
        ans += cnt[prefix];
        
        // Only add to counter if we're in the first array or second array but within valid range
        // For circular subarrays, we only want prefixes from positions that can form valid subarrays
        if(i < 2*n-1) { // Don't add the very last prefix as it can't start a new subarray
            cnt[prefix]++;
        }
    }
    
    cout << ans;
    return 0;
}