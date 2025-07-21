#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN],f[MAXN][2],last_parity[MAXN][2];

int main(){
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    f[0][0] = 0; // not selected
    last_parity[0][0] = 0; // parity of count (even)
    f[0][1] = -INF; // selected (invalid for 0th element)
    last_parity[0][1] = 1; // parity (odd, but not used)

    for(ll i=1;i<=n;i++){
        // Option 1: do not select a[i]
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if (f[i-1][0] > f[i-1][1]) {
            last_parity[i][0] = last_parity[i-1][0];
        } else {
            last_parity[i][0] = last_parity[i-1][1];
        }

        // Option 2: select a[i]
        ll select_not_double = f[i-1][0] + a[i];
        ll select_double = f[i-1][1] + a[i] * 2;
        if (last_parity[i-1][0] % 2 == 0) {
            select_not_double = f[i-1][0] + a[i];
        } else {
            select_not_double = f[i-1][0] + a[i] * 2;
        }
        if (last_parity[i-1][1] % 2 == 0) {
            select_double = f[i-1][1] + a[i];
        } else {
            select_double = f[i-1][1] + a[i] * 2;
        }

        if (select_not_double > select_double) {
            f[i][1] = select_not_double;
            last_parity[i][1] = last_parity[i-1][0] + 1;
        } else {
            f[i][1] = select_double;
            last_parity[i][1] = last_parity[i-1][1] + 1;
        }
    }
    printf("%lld",max(f[n][0], f[n][1]));
    return 0;
}