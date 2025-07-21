#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize DP tables
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    vector<vector<ll>> cnt(n, vector<ll>(2, 0));

    // Base case
    dp[0][0] = 0;
    dp[0][1] = a[0];
    cnt[0][0] = 0;
    cnt[0][1] = 1;

    for (ll i = 1; i < n; ++i) {
        // Option 1: Do not double the current number
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (dp[i - 1][0] > dp[i - 1][1])
            cnt[i][0] = cnt[i - 1][0];
        else
            cnt[i][0] = cnt[i - 1][1];

        // Option 2: Double the current number
        dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        if (dp[i - 1][0] + a[i] > dp[i - 1][1] + a[i])
            cnt[i][1] = cnt[i - 1][0] + 1;
        else
            cnt[i][1] = cnt[i - 1][1] + 1;
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    return 0;
}