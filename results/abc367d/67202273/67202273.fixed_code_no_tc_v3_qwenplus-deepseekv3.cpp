#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i];
    }
    
    sum[0] = 0;
    for(ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if(sum[i] < 0) sum[i] += m;  // Ensure positive remainder
    }
    
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;  // Initialize for empty prefix
    
    // First pass to count regular subarrays
    for(ll i = 1; i <= n; i++) {
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    // Second pass for circular cases
    memset(cnt, 0, sizeof(cnt));
    cnt[sum[0]] = 1;
    
    for(ll i = 1; i <= 2 * n; i++) {
        if(i > n) {
            ans += cnt[sum[i]];
            cnt[sum[i - n]]--;
        }
        cnt[sum[i]]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}