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
        sum[i+1]=(sum[i]+a[i])%m;
    }
    
    // Initialize frequency of prefix sums for first window
    for(ll i=0;i<=n;i++){
        cnt[sum[i]]++;
    }
    
    for(ll i=n+1;i<=2*n;i++){
        // Remove the prefix sum that's going out of window
        cnt[sum[i-n]]--;
        // Add pairs with current prefix sum
        ans += cnt[sum[i]];
        // Add current prefix sum to frequency map
        cnt[sum[i]]++;
    }
    
    printf("%lld",ans);
    return 0;
}