#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2],cnt[MAXN][2];
int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    
    // Initialize base case
    f[0][0] = 0; // Base case for previous sum of even counts
    f[0][1] = 0; // Base case for previous sum of odd counts
    cnt[0][0] = 0;
    cnt[0][1] = 1; // Start with 1 way to have odd count

    for(ll i=1; i<=n; ++i){
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        f[i][1] = max(f[i-1][0] + a[i], f[i-1][1] + a[i]);

        // Update count arrays
        cnt[i][0] = cnt[i-1][1]; // Carry over the odd count to previous even count
        cnt[i][1] = cnt[i-1][1] + 1; // Increment the odd count
    }

    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}