#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 105;

int n, x;
int a[MAXN], b[MAXN], p[MAXN], q[MAXN];

ll dp[MAXN][MAXN];

bool check(int mid) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s <= mid / a[i]; ++s) {
            for (int t = 0; t <= mid / b[i]; ++t) {
                if (dp[i - 1][s] != INT_MAX) {
                    dp[i][s + t] = min(dp[i][s + t], dp[i - 1][s] + (s * p[i]));
                }
                if (dp[i - 1][t] != INT_MAX) {
                    dp[i][s + t] = min(dp[i][s + t], dp[i - 1][t] + (t * q[i]));
                }
            }
        }
    }

    for (int s = 0; s <= mid / a[n]; ++s) {
        for (int t = 0; t <= mid / b[n]; ++t) {
            if (dp[n][s + t] != INT_MAX && dp[n][s + t] <= x) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = x;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;

    return 0;
}