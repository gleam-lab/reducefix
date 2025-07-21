#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2] = {INF, INF}, cnt[MAXN][2] = {0, 0};
int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++){
        // Calculate f[i][0] and f[i][1]
        f[i][0] = max(f[i-1][0], f[i-1][1] + (cnt[i-1][0] % 2 == 0 ? a[i] * 2 : a[i]));
        f[i][1] = max(f[i-1][0] + (cnt[i-1][1] % 2 == 0 ? a[i] * 2 : a[i]), f[i-1][1]);

        // Update counts
        cnt[i][0] = cnt[i-1][0] + (f[i][0] == f[i-1][0] ? 0 : 1);
        cnt[i][1] = cnt[i-1][1] + (f[i][1] == f[i-1][1] ? 0 : 1);
    }
    printf("%lld", max(f[n][0], f[n][1]));
    return 0;
}