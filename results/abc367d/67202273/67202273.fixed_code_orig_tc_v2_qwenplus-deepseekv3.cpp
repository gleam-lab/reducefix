#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN];
unordered_map<ll, ll> cnt;

int main(){
    ll n, m, ans=0;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        a[i+n] = a[i];
    }
    
    sum[0] = 0;
    for(ll i=1; i<=2*n; i++){
        sum[i] = (sum[i-1] + a[i]) % m;
    }
    
    cnt.clear();
    cnt[0] = 1; // Initialize with sum[0] = 0
    
    for(ll i=1; i<=n; i++){
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    cnt.clear();
    cnt[sum[n]] = 1; // Initialize for the second part
    
    for(ll i=n+1; i<=2*n; i++){
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
        // To avoid overlapping, we need to decrement the count of sum[i-n] when moving window
        if(i-n >=1){
            cnt[sum[i-n]]--;
        }
    }
    
    printf("%lld\n", ans);
    return 0;
}