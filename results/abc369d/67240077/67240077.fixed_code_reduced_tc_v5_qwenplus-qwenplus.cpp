#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;

ll a[MAXN], dp[MAXN][2]; // dp[i][0/1] 表示前i个数中选,且最后一个不选/选的情况下,的最优解
ll cnt[MAXN][2]; // 记录对应的奇偶性

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    dp[0][0] = 0; dp[0][1] = -INF;
    cnt[0][0] = 0; cnt[0][1] = 1;

    for(ll i=1;i<=n;i++){
        // 不选择第i个元素
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if(dp[i-1][0] > dp[i-1][1]){
            cnt[i][0] = cnt[i-1][0];
        }else if(dp[i-1][1] > dp[i-1][0]){
            cnt[i][0] = cnt[i-1][1];
        }else{
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }
        
        // 选择第i个元素
        ll val1 = dp[i-1][0] + a[i];
        ll val2 = dp[i-1][1] + (cnt[i-1][1]%2 == 0 ? a[i]*2 : a[i]);

        if(val1 > val2){
            dp[i][1] = val1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else {
            dp[i][1] = val2;
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }

    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}