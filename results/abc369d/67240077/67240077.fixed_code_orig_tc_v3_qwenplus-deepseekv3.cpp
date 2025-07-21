#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], dp[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    
    dp[0][0] = 0;
    dp[0][1] = -INF;
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    
    for (ll i = 1; i <= n; ++i) {
        // Option 1: Do not take the current element
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if (dp[i-1][0] > dp[i-1][1]) {
            cnt[i][0] = cnt[i-1][0];
        } else if (dp[i-1][1] > dp[i-1][0]) {
            cnt[i][0] = cnt[i-1][1];
        } else {
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }
        
        // Option 2: Take the current element
        ll val1 = a[i], val2 = a[i] * 2;
        ll new_cnt1 = cnt[i-1][0] + 1;
        ll new_cnt2 = cnt[i-1][1] + 1;
        ll sum1 = dp[i-1][0] + (new_cnt1 % 2 == 0 ? val2 : val1);
        ll sum2 = dp[i-1][1] + (new_cnt2 % 2 == 0 ? val2 : val1);
        
        if (sum1 > sum2) {
            dp[i][1] = sum1;
            cnt[i][1] = new_cnt1;
        } else if (sum2 > sum1) {
            dp[i][1] = sum2;
            cnt[i][1] = new_cnt2;
        } else {
            dp[i][1] = sum1;
            cnt[i][1] = min(new_cnt1, new_cnt2);
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}