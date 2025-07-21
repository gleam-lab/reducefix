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
        sum[i]=(sum[i-1]+a[i])%m; // Corrected index to start from 0-based array
        if(i>=n+1) cnt[sum[i-n]]++; // Adjusted condition to avoid out-of-bound access
    }
    for(ll i=n+1;i<=2*n;i++){
        cnt[sum[i-n]]--; // Corrected logic to decrement before checking count
        ans+=cnt[sum[i]]; // Fixed variable name 'ans' instead of 'ans='
        cnt[sum[i]]++; // Increment after updating answer
    }
    printf("%lld",ans);
	return 0;
}