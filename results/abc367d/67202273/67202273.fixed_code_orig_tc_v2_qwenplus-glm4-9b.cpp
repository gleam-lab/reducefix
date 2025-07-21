#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];
int main(){
    ll n, m, ans=0;
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = (i > 0 ? sum[i-1] : 0) + a[i];
        sum[i + n] = sum[i];
    }
    for(ll i = 0; i < 2 * n; i++) {
        sum[i + 1] = (sum[i] + a[i]) % m; // Correct modulo operation
    }
    for(ll i = 0; i < 2 * n; i++) {
        cnt[sum[i]]++;
    }
    for(ll i = n; i < 2 * n; i++) {
        ans += cnt[sum[i]];
        cnt[sum[i]]--;
    }
    printf("%lld\n", ans);
    return 0;
}