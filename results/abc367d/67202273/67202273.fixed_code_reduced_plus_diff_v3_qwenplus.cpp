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
    cnt[0]=n; // Initialize with 0 frequency for prefix sums starting at index 0
    for(ll i=n+1;i<=2*n;i++){
        cnt[sum[i-n]]--;
        ans+=cnt[sum[i]];
        cnt[sum[i]]++;
    }
    printf("%lld",ans);
    return 0;
}