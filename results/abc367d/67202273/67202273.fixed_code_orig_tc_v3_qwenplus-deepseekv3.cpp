#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;

int main(){
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    vector<ll> a(2 * n + 1);
    vector<ll> sum(2 * n + 2, 0);
    
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    
    for(ll i = 1; i <= 2 * n; i++){
        sum[i] = (sum[i - 1] + a[i]) % m;
    }
    
    unordered_map<ll, ll> cnt;
    for(ll i = 1; i <= n; i++){
        cnt[sum[i]]++;
    }
    
    for(ll i = n + 1; i <= 2 * n; i++){
        ans += cnt[sum[i]];
        cnt[sum[i - n]]--;
        cnt[sum[i]]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}