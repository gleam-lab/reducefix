#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN];
unordered_map<ll, ll> cnt;

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    sum[0] = 0;
    cnt[0] = 1; // Initialize with sum[0] = 0
    for(ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i-1] + a[i]) % m;
        if(i <= n) {
            cnt[sum[i]]++;
        }
    }
    ans = 0;
    for(ll i = n + 1; i <= 2 * n; i++) {
        ans += cnt[sum[i - n]];
        cnt[sum[i - n]]--;
        cnt[sum[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}