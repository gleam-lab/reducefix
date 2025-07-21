#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;  // Increased size to handle circular array properly
int n,m;
long long a[N], prefix[N];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];  // Create circular array
    }
    
    prefix[0] = 0;
    freq[0] = 1;  // Initialize for empty prefix
    long long res = 0;
    
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
        // We only count when i <= n for circular subarrays
        if(i > n) {
            // Remove the contribution from elements outside the window
            freq[(prefix[i-n] - prefix[0]) % m]--;
        }
        res += freq[prefix[i] % m];
        // We only add frequencies when i < n to avoid double counting
        if(i < n) {
            freq[prefix[i] % m]++;
        }
    }
    
    cout << res << '\n';
    return 0;
}