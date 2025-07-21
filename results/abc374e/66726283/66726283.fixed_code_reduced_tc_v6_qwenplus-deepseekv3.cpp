#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
const int INF=1e18;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total_cost = 0;
    for(int i = 1; i <= n; ++i) {
        int min_cost = INF;
        // Try all possible j (number of times method a is used)
        for(int j = 0; j <= b[i]; ++j) {
            if(mid < j * a[i]) continue;
            int remaining = mid - j * a[i];
            int k = (remaining + b[i] - 1) / b[i];
            if(k < 0) k = 0;
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        // Try all possible j (number of times method b is used)
        for(int j = 0; j <= a[i]; ++j) {
            if(mid < j * b[i]) continue;
            int remaining = mid - j * b[i];
            int k = (remaining + a[i] - 1) / a[i];
            if(k < 0) k = 0;
            min_cost = min(min_cost, j * q[i] + k * p[i]);
        }
        if(min_cost == INF) return false;
        total_cost += min_cost;
        if(total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 0, r = 1e18;
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}