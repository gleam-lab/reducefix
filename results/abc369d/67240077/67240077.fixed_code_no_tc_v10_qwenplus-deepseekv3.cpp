#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[0][0] = 0;       // previous element was not multiplied
    f[0][1] = -INF;     // previous element was multiplied (impossible for first element)
    
    for(ll i=1; i<=n; i++) {
        // Current element is not multiplied
        f[i][0] = max(f[i-1][0], f[i-1][1]) + a[i];
        
        // Current element is multiplied (can only follow non-multiplied)
        f[i][1] = f[i-1][0] + 2*a[i];
    }
    
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}