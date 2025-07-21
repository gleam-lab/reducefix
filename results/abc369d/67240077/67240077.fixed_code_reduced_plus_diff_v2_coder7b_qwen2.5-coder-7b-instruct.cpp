#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // dp array to store the maximum value at each step
    vector<ll> dp(n + 1, 0);
    // count array to store the number of operations needed
    vector<int> cnt(n + 1, 0);

    for (ll i = 1; i <= n; ++i) {
        // If the previous operation was doubling, do not double again
        if (cnt[i - 1] % 2 == 0) {
            dp[i] = dp[i - 1] + a[i];
            cnt[i] = cnt[i - 1] + 1;
        } else {
            // Otherwise, consider both options (doubling or adding as is)
            dp[i] = max(dp[i - 1] + a[i], dp[i - 1] + a[i] * 2);
            if (dp[i - 1] + a[i] > dp[i - 1] + a[i] * 2) {
                cnt[i] = cnt[i - 1] + 1;
            } else {
                cnt[i] = cnt[i - 1] + 2;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}