#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    f[0][0] = 0;       // not taking previous element
    f[0][1] = -INF;    // cannot take previous element initially
    cnt[0][0] = 0;
    cnt[0][1] = 0;
    
    for (ll i = 1; i <= n; i++) {
        // Option 1: don't take current element
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if (f[i-1][0] > f[i-1][1]) {
            cnt[i][0] = cnt[i-1][0];
        } else if (f[i-1][0] < f[i-1][1]) {
            cnt[i][0] = cnt[i-1][1];
        } else {
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }
        
        // Option 2: take current element
        ll take_from_0 = f[i-1][0] + (cnt[i-1][0] % 2 == 0 ? a[i] * 2 : a[i]);
        ll take_from_1 = f[i-1][1] + (cnt[i-1][1] % 2 == 0 ? a[i] * 2 : a[i]);
        f[i][1] = max(take_from_0, take_from_1);
        
        if (take_from_0 > take_from_1) {
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if (take_from_0 < take_from_1) {
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            cnt[i][1] = min(cnt[i-1][0], cnt[i-1][1]) + 1;
        }
    }
    
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}