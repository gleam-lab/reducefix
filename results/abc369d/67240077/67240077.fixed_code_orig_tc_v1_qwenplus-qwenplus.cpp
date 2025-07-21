#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
ll a[MAXN], dp[MAXN][2], cnt[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Initialize base cases
    dp[0][0] = 0;
    dp[0][1] = 0;
    cnt[0][0] = 0;
    cnt[0][1] = 0;

    for (ll i = 1; i <= n; ++i) {
        // Option 1: don't use current element
        if (dp[i - 1][0] > dp[i - 1][1]) {
            dp[i][0] = dp[i - 1][0];
            cnt[i][0] = cnt[i - 1][0];
        } else if (dp[i - 1][1] > dp[i - 1][0]) {
            dp[i][0] = dp[i - 1][1];
            cnt[i][0] = cnt[i - 1][1];
        } else {
            // Equal value, choose the one with smaller count to break tie consistently
            dp[i][0] = dp[i-1][0];
            if (cnt[i-1][0] <= cnt[i-1][1]) {
                cnt[i][0] = cnt[i-1][0];
            } else {
                cnt[i][0] = cnt[i-1][1];
            }
        }

        // Option 2: use current element
        ll use_val_0 = dp[i - 1][0] + ((cnt[i - 1][0] % 2 == 1) ? a[i] : 2 * a[i]);
        ll use_val_1 = dp[i - 1][1] + ((cnt[i - 1][1] % 2 == 1) ? a[i] : 2 * a[i]);

        if (use_val_0 > use_val_1) {
            dp[i][1] = use_val_0;
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else if (use_val_1 > use_val_0) {
            dp[i][1] = use_val_1;
            cnt[i][1] = cnt[i - 1][1] + 1;
        } else {
            // Tie in value: pick the one with smaller count for better future options
            if (cnt[i-1][0] <= cnt[i-1][1]) {
                dp[i][1] = use_val_0;
                cnt[i][1] = cnt[i-1][0] + 1;
            } else {
                dp[i][1] = use_val_1;
                cnt[i][1] = cnt[i-1][1] + 1;
            }
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}