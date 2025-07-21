#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (n); ++(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // dp[i] = 最大経験値（i体目まで倒したとき）
    vector<ll> dp(n);
    dp[0] = a[0];
    dp[1] = max(a[0] + a[1], a[1]); // 1体目だけ倒す or 2体目を倒す

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i],         // i体目を普通に倒す
                    dp[i - 2] + 2 * a[i]);    // i-1体目をスキップしてi体目を特技で倒す
    }

    cout << dp[n - 1] << endl;

    return 0;
}