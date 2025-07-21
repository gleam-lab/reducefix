#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll f[MAXN][2]; // f[i][0] = not take i, f[i][1] = take i
int cnt[MAXN][2]; // cnt[i][0] = count for not take i, cnt[i][1] = count for take i

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
        // Option 1: not take a[i]
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if(f[i-1][0] > f[i-1][1]){
            cnt[i][0] = cnt[i-1][0];
        } else if(f[i-1][1] > f[i-1][0]){
            cnt[i][0] = cnt[i-1][1];
        } else {
            // If equal, choose the one with smaller count to potentially allow more doubling later
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }

        // Option 2: take a[i]
        ll take0, take1;
        take0 = f[i-1][0] + ((cnt[i-1][0] % 2 == 0) ? a[i] * 2 : a[i]);
        take1 = f[i-1][1] + ((cnt[i-1][1] % 2 == 0) ? a[i] * 2 : a[i]);
        if(take0 > take1){
            f[i][1] = take0;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if(take1 > take0){
            f[i][1] = take1;
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            // If equal, choose the one with smaller count to potentially allow more doubling later
            if(cnt[i-1][0] + 1 < cnt[i-1][1] + 1){
                f[i][1] = take0;
                cnt[i][1] = cnt[i-1][0] + 1;
            } else {
                f[i][1] = take1;
                cnt[i][1] = cnt[i-1][1] + 1;
            }
        }
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}