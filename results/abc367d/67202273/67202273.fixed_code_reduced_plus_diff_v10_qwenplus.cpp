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
    sum[0] = 0;
    for(ll i=1;i<=2*n;i++){
        sum[i]=(sum[i-1]+a[i])%m;
    }
    
    // Initialize frequency of prefix sums for first window
    cnt[0] = n; // sum[0] appears n times due to circular nature
    for(ll i=1;i<=n;i++){
        cnt[sum[i]]++;
    }
    
    for(ll i=n+1;i<=2*n;i++){
        // Remove the contribution of sum[i-n-1]
        cnt[sum[i-n-1]]--;
        
        // Add pairs where (sum[i] - sum[j]) % m == 0 => sum[j] == sum[i]
        ans += cnt[sum[i]];
        
        // Add current prefix sum to frequency map
        cnt[sum[i]]++;
    }
    
    printf("%lld",ans);
    return 0;
}