#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] = not take i, dp[i][1] = take i
ll cnt[MAXN][2]; // cnt[i][0] = count of selected elements when not take i, cnt[i][1] = count when take i

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
        if(dp[i-1][0] > dp[i-1][1]) {
            dp[i][0] = dp[i-1][0];
            cnt[i][0] = cnt[i-1][0];
        } else {
            dp[i][0] = dp[i-1][1];
            cnt[i][0] = cnt[i-1][1];
        }
        
        // Option 2: take a[i]
        ll take_from_0 = dp[i-1][0] + ((cnt[i-1][0] % 2 == 0) ? a[i] * 2 : a[i]);
        ll take_from_1 = dp[i-1][1] + ((cnt[i-1][1] % 2 == 0) ? a[i] * 2 : a[i]);
        
        if(take_from_0 > take_from_1) {
            dp[i][1] = take_from_0;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else {
            dp[i][1] = take_from_1;
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}