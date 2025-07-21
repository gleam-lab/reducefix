#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2];
ll cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    
    dp[0][0] = 0;
    dp[0][1] = -INF;
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    
    for(ll i=1; i<=n; i++) {
        // Option 1: not take a[i]
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if (dp[i-1][0] > dp[i-1][1]) {
            cnt[i][0] = cnt[i-1][0];
        } else if (dp[i-1][1] > dp[i-1][0]) {
            cnt[i][0] = cnt[i-1][1];
        } else {
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }
        
        // Option 2: take a[i]
        ll val1 = (cnt[i-1][0] + 1) % 2 == 0 ? a[i] * 2 : a[i];
        ll val2 = (cnt[i-1][1] + 1) % 2 == 0 ? a[i] * 2 : a[i];
        ll sum1 = dp[i-1][0] + val1;
        ll sum2 = dp[i-1][1] + val2;
        if (sum1 > sum2) {
            dp[i][1] = sum1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if (sum2 > sum1) {
            dp[i][1] = sum2;
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            dp[i][1] = sum1;
            cnt[i][1] = min(cnt[i-1][0] + 1, cnt[i-1][1] + 1);
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}