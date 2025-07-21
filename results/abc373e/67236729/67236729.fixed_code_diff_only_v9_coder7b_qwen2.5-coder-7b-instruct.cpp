#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> suffix_sum(n + 1);
    suffix_sum[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
    }

    vector<ll> dp(n + 1, -1);
    dp[m] = 0;

    for (int i = m + 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j] != -1 && suffix_sum[j] + dp[j] < a[j]) {
                dp[j] = -1;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (dp[j] != -1 && suffix_sum[j] + dp[j] >= a[j]) {
                dp[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] != -1) {
            cout << dp[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}