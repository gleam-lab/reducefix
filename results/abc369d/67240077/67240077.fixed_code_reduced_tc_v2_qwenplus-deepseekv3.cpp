#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], dp[MAXN][2], cnt[MAXN][2];

int main(){
    ll n;
    scanf("%lld", &n);
    for(ll i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    
    dp[0][0] = 0;
    dp[0][1] = -INF;
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    
    for(ll i=1; i<=n; i++){
        // Not taking a[i]
        if(dp[i-1][0] > dp[i-1][1]){
            dp[i][0] = dp[i-1][0];
            cnt[i][0] = cnt[i-1][0];
        } else if(dp[i-1][0] < dp[i-1][1]){
            dp[i][0] = dp[i-1][1];
            cnt[i][0] = cnt[i-1][1];
        } else {
            dp[i][0] = dp[i-1][0];
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }
        
        // Taking a[i]
        ll val1, val2;
        if(cnt[i-1][0] % 2 == 0){
            val1 = a[i] * 2;
        } else {
            val1 = a[i];
        }
        if(cnt[i-1][1] % 2 == 0){
            val2 = a[i] * 2;
        } else {
            val2 = a[i];
        }
        
        ll option1 = dp[i-1][0] + val1;
        ll option2 = dp[i-1][1] + val2;
        
        if(option1 > option2){
            dp[i][1] = option1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if(option1 < option2){
            dp[i][1] = option2;
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            dp[i][1] = option1;
            cnt[i][1] = min(cnt[i-1][0] + 1, cnt[i-1][1] + 1);
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}