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
        sum[i]=sum[i-1]+a[i]; // Calculate prefix sum
        sum[i]%=m; // Take modulo m
    }
    for(ll i=1;i<=m;i++) cnt[i]=0; // Initialize count for each modulo m value
    for(ll i=1;i<=2*n;i++) cnt[sum[i]]++; // Count frequency of each prefix sum modulo m
    for(ll i=1;i<=n;i++) cnt[sum[i]]--; // Decrease count for the prefix sum that wraps around
    for(ll i=1;i<=m;i++) ans+=cnt[i]; // Sum up the frequencies
    printf("%lld",ans);
	return 0;
}