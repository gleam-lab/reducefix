#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],prefix[N],mod_count[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] %= m;
        if(a[i] < 0) a[i] += m;
    }
    
    mod_count[0] = 1;
    prefix[0] = 0;
    
    for(int i=1;i<=n;i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m;
        sum += mod_count[prefix[i]];
        mod_count[prefix[i]]++;
    }
    
    // Now handle the circular case (subarrays that wrap around)
    // We need to consider subarrays that start at i+1 and end at i (circular)
    // To do this, we'll concatenate the array with itself and use sliding window
    // But with a more efficient approach
    
    // Make the array circular by doubling it
    for(int i=1;i<=n;i++) {
        a[i+n] = a[i];
    }
    
    // Reset for circular processing
    memset(mod_count, 0, sizeof(mod_count));
    mod_count[0] = 1;
    long long circular_sum = 0;
    int current_mod = 0;
    
    // We need to consider subarrays of length up to n
    // So we use a sliding window of size n
    for(int i=1;i<=2*n;i++) {
        current_mod = (current_mod + a[i]) % m;
        if(current_mod < 0) current_mod += m;
        
        if(i > n) {
            int prev_mod = (current_mod - prefix[i-n] % m + m) % m;
            circular_sum += mod_count[prev_mod];
            mod_count[(current_mod - prefix[i-n] % m + m) % m]--;
        }
        
        if(i <= n) {
            mod_count[current_mod]++;
        }
    }
    
    cout << sum + circular_sum << endl;
    return 0;
}