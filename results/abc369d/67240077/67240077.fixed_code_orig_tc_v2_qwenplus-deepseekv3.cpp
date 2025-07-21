#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][3];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    f[0][0] = 0;
    f[0][1] = -INF;
    f[0][2] = -INF;
    for(ll i=1;i<=n;i++){
        f[i][0] = max(f[i-1][0], max(f[i-1][1], f[i-1][2]));
        f[i][1] = f[i-1][0] + a[i];
        f[i][2] = f[i-1][1] + a[i] * 2;
    }
    printf("%lld",max(f[n][0], max(f[n][1], f[n][2])));
    return 0;
}