#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
ll cnt[MAXN][2]; // cnt[i][j] stores the number of selected elements in the i-th state j

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize base cases
    f[0][0] = 0; // Not taking ith element
    f[0][1] = 0; // Taking ith element
    cnt[0][0] = 0; // Count when not taking ith element
    cnt[0][1] = 1; // Count when taking ith element

    for (ll i = 1; i <= n; i++) {
        // Option: do not take a[i]
        if (f[i - 1][0] > f[i - 1][1]) {
            f[i][0] = f[i - 1][0];
            cnt[i][0] = cnt[i - 1][0];
        } else {
            f[i][0] = f[i - 1][1];
            cnt[i][0] = cnt[i - 1][1];
        }

        // Option: take a[i]
        ll val1, val2;
        val1 = f[i - 1][0] + a[i]; // previous count is even -> current count becomes odd
        val2 = f[i - 1][1] + ((cnt[i - 1][1] % 2 == 1) ? a[i] : a[i] * 2); // previous count is odd

        if (val1 > val2) {
            f[i][1] = val1;
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else {
            f[i][1] = val2;
            cnt[i][1] = cnt[i - 1][1] + 1;
        }
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}