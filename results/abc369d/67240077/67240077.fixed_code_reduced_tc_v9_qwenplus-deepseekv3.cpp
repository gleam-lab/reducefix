#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll dp[MAXN][2]; // dp[i][0] = even count, dp[i][1] = odd count

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    dp[0][0] = 0; // even count (0 elements selected)
    dp[0][1] = -INF; // impossible to have odd count with 0 elements
    
    for(ll i=1;i<=n;i++){
        // Option 1: do not select a[i]
        ll temp0 = max(dp[i-1][0], dp[i-1][1]);
        ll temp1 = -INF;
        
        // Option 2: select a[i]
        // From even count (previous selection count was even)
        ll val0 = dp[i-1][0] + a[i];
        // From odd count (previous selection count was odd)
        ll val1 = dp[i-1][1] + 2 * a[i];
        
        // The new count after selection is previous count + 1
        // So even becomes odd, and odd becomes even
        temp1 = max(val0, val1);
        
        // Update dp[i][0] and dp[i][1]
        // After selecting a[i], even count becomes odd, and vice versa
        dp[i][0] = max(temp0, temp1); // not selecting keeps count, selecting flips it
        // Wait, no. Need to separate the counts.
        // Actually, temp0 is not selecting, so count remains as previous.
        // temp1 is selecting, so count increases by 1.
        // So:
        dp[i][0] = temp0; // no selection, count remains same
        dp[i][1] = temp1; // selection, count increases by 1
        // But we need to track the count parity.
        // So dp[i][0] is max of not selecting (count remains previous)
        // dp[i][1] is max of selecting (count increases by 1, so parity flips)
        // So:
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]); // no selection
        // dp[i][1] = max(dp[i-1][0] + a[i], dp[i-1][1] + 2 * a[i]); // selection
    }
    
    printf("%lld\n", max(dp[n][0], dp[n][1]));
    return 0;
}