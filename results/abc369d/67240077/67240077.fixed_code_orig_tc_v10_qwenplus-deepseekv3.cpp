#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2][2]; // f[i][j][k] - j: whether current is taken, k: whether previous was taken

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize DP
    f[0][0][0] = 0;
    f[0][0][1] = -INF;
    f[0][1][0] = -INF;
    f[0][1][1] = -INF;
    
    for(ll i=1;i<=n;i++){
        // Case 1: Don't take current element
        f[i][0][0] = max(f[i-1][0][0], f[i-1][0][1]);
        f[i][0][1] = max(f[i-1][1][0], f[i-1][1][1]);
        
        // Case 2: Take current element
        // If previous wasn't taken, double current
        f[i][1][0] = max(f[i-1][0][0], f[i-1][0][1]) + a[i] * 2;
        // If previous was taken, don't double current
        f[i][1][1] = max(f[i-1][1][0], f[i-1][1][1]) + a[i];
    }
    
    printf("%lld",max(max(f[n][0][0], f[n][0][1]), max(f[n][1][0], f[n][1][1])));
    return 0;
}