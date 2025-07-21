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
    f[1][0] = 0;
    f[1][1] = a[1];
    cnt[1][0] = 0;
    cnt[1][1] = 1;
    for(ll i=2;i<=n;i++){
        // Not selecting the i-th element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if(f[i-1][0] > f[i-1][1]) {
            cnt[i][0] = cnt[i-1][0];
        } else {
            cnt[i][0] = cnt[i-1][1];
        }
        
        // Selecting the i-th element
        ll select_from_0, select_from_1;
        if(cnt[i-1][0] % 2 == 0) {
            select_from_0 = f[i-1][0] + a[i];
        } else {
            select_from_0 = f[i-1][0] + 2 * a[i];
        }
        if(cnt[i-1][1] % 2 == 0) {
            select_from_1 = f[i-1][1] + a[i];
        } else {
            select_from_1 = f[i-1][1] + 2 * a[i];
        }
        
        f[i][1] = max(select_from_0, select_from_1);
        if(select_from_0 > select_from_1) {
            cnt[i][1] = cnt[i-1][0] + 1;
        } else {
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }
    printf("%lld",max(f[n][0], f[n][1]));
    return 0;
}