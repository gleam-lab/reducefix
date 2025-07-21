#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], dp[MAXN][2][2]; // dp[i][j][k], j: selected or not, k: parity of count

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize DP
    dp[0][0][0] = 0;
    dp[0][0][1] = -INF;
    dp[0][1][0] = -INF;
    dp[0][1][1] = -INF;
    
    for(ll i=1;i<=n;i++){
        // Not selecting the i-th element
        dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
        dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]);
        
        // Selecting the i-th element
        // From not selecting i-1
        ll val1 = a[i]; // previous count is 0 (even)
        dp[i][1][1] = dp[i-1][0][0] + val1;
        
        // From selecting i-1
        ll val2 = (dp[i-1][1][0] != -INF) ? a[i] * 2 : -INF; // previous count was odd (1)
        ll val3 = (dp[i-1][1][1] != -INF) ? a[i] : -INF; // previous count was even (0 mod 2)
        
        dp[i][1][0] = max(val2, val3);
    }
    
    printf("%lld", max(max(dp[n][0][0], dp[n][0][1]), max(dp[n][1][0], dp[n][1][1])));
    return 0;
}