#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN];
ll f[MAXN][2]; // f[i][0] = not take i, f[i][1] = take i
ll cnt[MAXN][2]; // cnt[i][0] = count of taken elements for f[i][0], similarly for f[i][1]

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
        // Option 1: Do not take a[i]
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if(f[i-1][0] > f[i-1][1]) {
            cnt[i][0] = cnt[i-1][0];
        } else if(f[i-1][0] < f[i-1][1]) {
            cnt[i][0] = cnt[i-1][1];
        } else {
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }

        // Option 2: Take a[i]
        ll num1 = (cnt[i-1][0] % 2 == 1) ? a[i] * 2 : a[i];
        ll sum1 = f[i-1][0] + num1;
        ll num2 = (cnt[i-1][1] % 2 == 1) ? a[i] * 2 : a[i];
        ll sum2 = f[i-1][1] + num2;
        if(sum1 > sum2) {
            f[i][1] = sum1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if(sum1 < sum2) {
            f[i][1] = sum2;
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            f[i][1] = sum1;
            cnt[i][1] = min(cnt[i-1][0] + 1, cnt[i-1][1] + 1);
        }
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}