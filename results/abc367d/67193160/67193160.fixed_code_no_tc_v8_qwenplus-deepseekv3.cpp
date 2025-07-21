#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[N*2], prefix[N*2];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // make circular
    }
    
    prefix[0] = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    
    long long res = 0;
    freq[0] = 1; // empty prefix
    
    for(int i=1; i<=2*n; i++) {
        if(i > n) {
            // Remove the contribution from the prefix that's now out of window
            long long prev_sum = prefix[i-n-1];
            freq[prev_sum % m]--;
        }
        
        res += freq[prefix[i] % m];
        freq[prefix[i] % m]++;
    }
    
    cout << res;
    return 0;
}