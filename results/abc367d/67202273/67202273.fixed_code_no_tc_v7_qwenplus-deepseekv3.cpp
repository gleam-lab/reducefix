#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], prefix[MAXN];
unordered_map<ll, ll> cnt;

int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=n; i++){
        scanf("%lld", &a[i]);
        a[i+n] = a[i];  // Create circular array
    }
    
    prefix[0] = 0;
    cnt[0] = 1;
    ll ans = 0;
    
    for(ll i=1; i<=2*n; i++){
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(i > n){  // Only count when we have full subarrays
            cnt[prefix[i-n]]--;  // Remove the prefix that's now out of range
            ans += cnt[prefix[i]];
        }
        cnt[prefix[i]]++;
    }
    
    printf("%lld", ans);
    return 0;
}