#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],prefix[N],cnt[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= m;
        if(a[i] < 0) a[i] += m;
    }
    
    // Calculate prefix sums
    prefix[0] = 0;
    for(int i=1; i<=n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m;
    }
    
    // Handle circular case by concatenating array
    long long res = 0;
    cnt[0] = 1;  // empty prefix
    
    // First pass for non-circular subarrays
    for(int i=1; i<=n; i++) {
        res += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    // Second pass for circular subarrays
    for(int i=1; i<=n; i++) {
        prefix[i+n] = (prefix[i+n-1] + a[i]) % m;
        if(prefix[i+n] < 0) prefix[i+n] += m;
    }
    
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    
    for(int i=1; i<=2*n; i++) {
        if(i > n) {
            cnt[prefix[i-n]]--;
        }
        res += cnt[prefix[i]];
        if(i < n) {
            cnt[prefix[i]]++;
        }
    }
    
    cout << res << endl;
    return 0;
}