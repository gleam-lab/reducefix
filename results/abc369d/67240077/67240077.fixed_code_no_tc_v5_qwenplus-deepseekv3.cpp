#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] = max sum up to i with even count, dp[i][1] = odd count

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize base cases
    dp[0][0] = 0;       // 0 elements selected (even count)
    dp[0][1] = -1e18;   // Impossible to have odd count with 0 elements
    
    for(ll i=1;i<=n;i++){
        // Option 1: Don't select current element
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = -1e18; // Not possible if we don't select
        
        // Option 2: Select current element
        // If previous count was even, now becomes odd (value is a[i])
        if(dp[i][1] < dp[i-1][0] + a[i]){
            dp[i][1] = dp[i-1][0] + a[i];
        }
        // If previous count was odd, now becomes even (value is 2*a[i])
        if(dp[i][0] < dp[i-1][1] + 2*a[i]){
            dp[i][0] = dp[i-1][1] + 2*a[i];
        }
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}