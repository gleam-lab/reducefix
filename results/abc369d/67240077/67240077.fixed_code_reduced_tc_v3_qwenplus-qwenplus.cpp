#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
// f[i][0] = max value considering first i elements, last chosen element is not doubled (or parity doesn't matter)
// f[i][1] = max value considering first i elements, last chosen element is doubled

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize base cases
    f[0][0] = 0;
    f[0][1] = 0;

    for (ll i = 1; i <= n; i++) {
        // Case: don't choose a[i]
        f[i][0] = max(f[i-1][0], f[i-1][1]);

        // Case: choose a[i]
        // If previous was not doubled, current count is odd -> a[i] is normal
        ll val1 = f[i-1][0] + a[i];
        // If previous was doubled, current count is even -> a[i] is doubled
        ll val2 = f[i-1][1] + a[i] * 2;
        f[i][1] = max(val1, val2);
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}