#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,a[N],prefix[2*N],cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Create circular array
    }
    
    // Compute prefix sums
    prefix[0] = 0;
    for(int i=1;i<=2*n;i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    
    cnt[0] = 1; // Empty prefix has sum 0
    long long total = 0;
    
    // For the linear case (non-circular)
    for(int i=1;i<=n;i++) {
        int mod = (prefix[i] % m + m) % m;
        total += cnt[mod];
        cnt[mod]++;
    }
    
    // For the circular case, we need to consider all subarrays of length <=n
    // but we've already counted subarrays within first n elements
    // Now we need to consider subarrays that wrap around
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    
    for(int i=n+1;i<=2*n;i++) {
        int mod = (prefix[i] % m + m) % m;
        total += cnt[mod];
        cnt[mod]++;
    }
    
    cout << total;
    return 0;
}