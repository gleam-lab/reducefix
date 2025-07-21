#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    vector<int> dp(mid + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        vector<int> new_dp(dp.begin(), dp.end());
        for (int j = 0; j <= mid; ++j) {
            if (j >= a[i]) {
                new_dp[j] = min(new_dp[j], dp[j - a[i]] + p[i]);
            }
            if (j >= b[i]) {
                new_dp[j] = min(new_dp[j], dp[j - b[i]] + q[i]);
            }
        }
        swap(dp, new_dp);
    }
    
    for (int i = 0; i <= mid; ++i) {
        if (dp[i] <= x) {
            return true;
        }
    }
    
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    int l = 0, r = x;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    cout << l;
    return 0;
}