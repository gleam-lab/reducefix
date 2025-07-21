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
    f[0][0] = 0;
    f[0][1] = -INF;
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    for(ll i=1;i<=n;i++){
        // Option 1: not take the current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if(f[i-1][0] > f[i-1][1]){
            cnt[i][0] = cnt[i-1][0];
        } else if(f[i-1][0] < f[i-1][1]){
            cnt[i][0] = cnt[i-1][1];
        } else {
            // If both are equal, choose the one with smaller count
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }

        // Option 2: take the current element
        ll take0, take1;
        if(cnt[i-1][0] % 2 == 0){
            take0 = f[i-1][0] + a[i] * 2;
        } else {
            take0 = f[i-1][0] + a[i];
        }
        if(cnt[i-1][1] % 2 == 0){
            take1 = f[i-1][1] + a[i] * 2;
        } else {
            take1 = f[i-1][1] + a[i];
        }
        f[i][1] = max(take0, take1);
        if(take0 > take1){
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if(take0 < take1){
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            // If both are equal, choose the one with smaller count
            cnt[i][1] = min(cnt[i-1][0], cnt[i-1][1]) + 1;
        }
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}