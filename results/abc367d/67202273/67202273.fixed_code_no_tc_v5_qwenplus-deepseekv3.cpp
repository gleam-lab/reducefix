#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;
ll a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    ll n, m, ans = 0;
    scanf("%lld %lld", &n, &m);
    
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i + n] = a[i]; // Create circular array
    }
    
    memset(cnt, 0, sizeof(cnt)); // Initialize cnt to zero
    sum[0] = 0;
    
    for (ll i = 1; i <= 2 * n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (sum[i] < 0) sum[i] += m; // Ensure non-negative
    }
    
    cnt[0] = 1; // Initialize for prefix sum from 0
    
    for (ll i = 1; i <= 2 * n; i++) {
        if (i > n) {
            // Remove the prefix sum of the left end when sliding window exceeds n
            cnt[sum[i - n]]--;
        }
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    
    printf("%lld\n", ans);
    return 0;
}