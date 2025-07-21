#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
ll cnt[MAXN][2]; // cnt[i][j] stores the number of selected elements in the i-th state j (0 or 1)

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    // Initialize base cases
    f[0][0] = 0; // No elements taken, not taking current
    f[0][1] = 0; // No elements taken, not taking current
    cnt[0][0] = 0; // Count of items picked when not taking current
    cnt[0][1] = 0;

    for (ll i = 1; i <= n; ++i) {
        // Case 0: do not take the ith element
        if (f[i - 1][0] > f[i - 1][1]) {
            f[i][0] = f[i - 1][0];
            cnt[i][0] = cnt[i - 1][0];
        } else if (f[i - 1][1] > f[i - 1][0]) {
            f[i][0] = f[i - 1][1];
            cnt[i][0] = cnt[i - 1][1];
        } else {
            // If equal, choose minimum count to allow more flexibility
            f[i][0] = f[i - 1][0];
            cnt[i][0] = min(cnt[i - 1][0], cnt[i - 1][1]);
        }

        // Case 1: take the ith element
        ll prev0_cnt = cnt[i - 1][0] + 1;
        ll prev1_cnt = cnt[i - 1][1] + 1;

        ll val0, val1;
        if (prev0_cnt % 2 == 0) val0 = a[i] * 2;
        else val0 = a[i];

        if (prev1_cnt % 2 == 0) val1 = a[i] * 2;
        else val1 = a[i];

        ll option0 = f[i - 1][0] + val0;
        ll option1 = f[i - 1][1] + val1;

        if (option0 > option1) {
            f[i][1] = option0;
            cnt[i][1] = prev0_cnt;
        } else if (option1 > option0) {
            f[i][1] = option1;
            cnt[i][1] = prev1_cnt;
        } else {
            // If equal, pick one with fewer selections
            f[i][1] = option0;
            cnt[i][1] = min(prev0_cnt, prev1_cnt);
        }
    }

    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}