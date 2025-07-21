#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN];
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
    map<ll, ll> cnt;
    cnt[0] = 1;
    for(ll i=1; i<=2*n; i++){
        if(i > n){
            ll prev_mod = sum[i-n];
            cnt[prev_mod]--;
            if(cnt[prev_mod] == 0){
                cnt.erase(prev_mod);
            }
        }
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}