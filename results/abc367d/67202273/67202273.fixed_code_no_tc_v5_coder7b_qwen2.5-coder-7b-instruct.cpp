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
        a[i+n]=a[i];
    }
    for(ll i=1;i<=2*n;i++){
        sum[i]=((sum[i-1]+a[i])%m+m)%m; // Ensure non-negative result
        if(i>n) cnt[sum[i]]++; // Start counting after the first full cycle
    }
    for(ll i=n+1;i<=2*n;i++){
        cnt[sum[i-n]]--; // Decrease count of the old prefix sum
        ans=(ans+cnt[sum[i]])%m; // Update answer with current valid pairs
        cnt[sum[i]]++; // Increase count of the new prefix sum
    }
    printf("%lld\n",ans);
	return 0;
}