#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,a[N],prefix[2*N],cnt[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Create circular array
    }
    
    // Compute prefix sums for circular array
    prefix[0] = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    // Initialize count for prefix[0] = 0
    cnt[0] = 1;
    sum = 0;
    
    // Count subarrays for the first n elements
    for(int i=1; i<=n; i++) {
        sum += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    // Now handle the circular part by sliding window
    // Remove the contribution of elements leaving the window
    for(int i=n+1; i<=2*n; i++) {
        cnt[prefix[i-n]]--;
        sum += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    cout << sum;
    return 0;
}