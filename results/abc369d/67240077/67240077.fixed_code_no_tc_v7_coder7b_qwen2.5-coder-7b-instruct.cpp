#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2], cnt[MAXN][2];

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize base case
    f[1][0] = 0;
    f[1][1] = a[1];
    cnt[1][0] = 0;
    cnt[1][1] = 1;

    for (ll i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        cnt[i][0] = cnt[i - 1][0];
        if (f[i - 1][0] == f[i - 1][1]) {
            cnt[i][0]++;
        }

        ll num1 = a[i];
        ll num2 = a[i];
        if ((cnt[i - 1][0] + 1) % 2 == 0) {
            num1 *= 2;
        }
        if ((cnt[i - 1][1] + 1) % 2 == 0) {
            num2 *= 2;
        }

        f[i][1] = max(f[i - 1][0] + num1, f[i - 1][1] + num2);
        if (f[i - 1][0] + num1 > f[i - 1][1] + num2) {
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else {
            cnt[i][1] = cnt[i - 1][1] + 1;
        }
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}