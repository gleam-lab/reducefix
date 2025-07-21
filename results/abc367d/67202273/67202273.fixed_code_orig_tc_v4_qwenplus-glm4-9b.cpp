#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN],sum[MAXN],cnt[MAXN];
int main(){
    ll n,m,ans=0;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i]; // Copy the array
    }
    for(ll i=1;i<=2*n;i++){
        sum[i+1]=sum[i]+a[i]; // Compute prefix sum, but after this line it will overflow
        sum[i+1] %= m;
        if(i<=n) cnt[sum[i]]++;
    }
    for(ll i=n+1;i<=2*n;i++){
        if(i-n>=1) cnt[sum[i-n]]--; // Only decrement if the index is within bounds
        ans=ans+cnt[sum[i]];
        cnt[sum[i]]++;
    }
    printf("%lld",ans);
	return 0;
}