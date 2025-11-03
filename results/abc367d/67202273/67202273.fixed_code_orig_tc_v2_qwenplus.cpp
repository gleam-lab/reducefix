#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN],sum[MAXN];
map<ll,ll> cnt;

int main(){
    ll n,m,ans=0;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i];
    }
    for(ll i=1;i<=2*n;i++){
        sum[i]=(sum[i-1]+a[i])%m;
    }
    
    // Initialize frequency map with prefix sums from first segment
    cnt[0] = 1;  // sum[0] = 0
    for(ll i=1; i<=n; i++) {
        cnt[sum[i]]++;
    }
    
    // Sliding window: remove leftmost prefix, add new prefix
    for(ll i=n+1; i<=2*n; i++) {
        // Remove sum[i-n-1] which is now out of window
        cnt[sum[i-n-1]]--;
        
        // Count how many previous prefixes have same value as current sum[i]
        ans += cnt[sum[i]];
        
        // Add current prefix to the map
        cnt[sum[i]]++;
    }
    
    printf("%lld",ans);
    return 0;
}