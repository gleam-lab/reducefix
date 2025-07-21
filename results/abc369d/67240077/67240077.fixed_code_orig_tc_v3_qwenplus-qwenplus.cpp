#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
int cnt[MAXN][2]; // Count of selections in each state

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // Initialize for DP
    cnt[0][0] = 0; // Not taking the 0th element, count is 0
    cnt[0][1] = 0; // Invalid initially, but will be updated

    for (ll i = 1; i <= n; i++) {
        // Case: not taking a[i]
        if (f[i-1][0] > f[i-1][1]) {
            f[i][0] = f[i-1][0];
            cnt[i][0] = cnt[i-1][0];
        } else if (f[i-1][1] > f[i-1][0]) {
            f[i][0] = f[i-1][1];
            cnt[i][0] = cnt[i-1][1];
        } else {
            // Equal value, prefer smaller count to minimize impact on even/odd
            f[i][0] = f[i-1][0];
            cnt[i][0] = min(cnt[i-1][0], cnt[i-1][1]);
        }

        // Case: taking a[i]
        ll num1 = (cnt[i-1][0] % 2 == 0) ? a[i] * 2 : a[i];
        ll num2 = (cnt[i-1][1] % 2 == 0) ? a[i] * 2 : a[i];

        if (f[i-1][0] + num1 > f[i-1][1] + num2) {
            f[i][1] = f[i-1][0] + num1;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else if (f[i-1][1] + num2 > f[i-1][0] + num1) {
            f[i][1] = f[i-1][1] + num2;
            cnt[i][1] = cnt[i-1][1] + 1;
        } else {
            // Tie in value: choose the one with fewer elements to maintain better parity
            ll cnt1 = cnt[i-1][0] + 1;
            ll cnt2 = cnt[i-1][1] + 1;
            f[i][1] = f[i-1][0] + num1;
            cnt[i][1] = (cnt1 < cnt2) ? cnt1 : cnt2;
        }
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}