#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
ll a[MAXN], f[MAXN][2], c[MAXN][2];

ll max3(ll a, ll b, ll c) {
    return max(max(a, b), c);
}

int main() {
    ll n;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    f[1][0] = a[1];
    if(n > 1) {
        f[2][0] = max(a[1], a[2]);
        f[2][1] = f[1][0] + a[2];
        c[2][0] = 2;
        c[2][1] = 1;
    }

    for(ll i = 3; i <= n; i++) {
        f[i][0] = max3(f[i-1][0], f[i-2][0], f[i-2][1]) + a[i];
        f[i][1] = max3(f[i-1][0] + a[i], f[i-2][0] + a[i], f[i-1][1] + a[i]) + a[i];

        if(f[i-1][0] + a[i] == f[i][1]) {
            c[i][1] = c[i-1][0] + 1;
            c[i][0] = c[i-2][0];
        } else if(f[i-2][0] + a[i] == f[i][1]) {
            c[i][1] = c[i-2][1];
            c[i][0] = c[i-2][0] + 1;
        } else {
            c[i][1] = c[i-1][1] + 1;
            c[i][0] = c[i-1][0];
        }
    }

    ll result = max3(f[n][0], f[n][1], f[n-1][1]);
    printf("%lld", result);
    return 0;
}