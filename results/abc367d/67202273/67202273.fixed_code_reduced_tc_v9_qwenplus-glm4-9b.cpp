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
        sum[i+1] = (sum[i] + a[i]) % m;
    }
    for(ll i=1;i<=n;i++){
        cnt[sum[i]]++;
    }
    for(ll i=n+1;i<=2*n;i++){
        cnt[sum[i]]++;
        ans += cnt[sum[i]];
        cnt[sum[i]]--;
    }
    printf("%lld\n",ans);
    return 0;
}