#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
int cnt[MAXN][2]; // count of selections in the path

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize base case
    f[0][0] = 0;
    f[0][1] = a[1];
    cnt[0][0] = 0;
    cnt[0][1] = 1;

    for (ll i = 1; i < n; i++) {
        // Case: not taking element i
        if (f[i - 1][0] > f[i - 1][1]) {
            f[i][0] = f[i - 1][0];
            cnt[i][0] = cnt[i - 1][0];
        } else {
            f[i][0] = f[i - 1][1];
            cnt[i][0] = cnt[i - 1][1];
        }

        // Case: taking element i
        ll take_odd_0 = f[i - 1][0] + (cnt[i - 1][0] % 2 == 0 ? a[i] * 2 : a[i]);
        ll take_odd_1 = f[i - 1][1] + (cnt[i - 1][1] % 2 == 0 ? a[i] * 2 : a[i]);

        if (take_odd_0 > take_odd_1) {
            f[i][1] = take_odd_0;
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else {
            f[i][1] = take_odd_1;
            cnt[i][1] = cnt[i - 1][1] + 1;
        }
    }

    printf("%lld\n", max(f[n - 1][0], f[n - 1][1]));
    return 0;
}