#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
const int INF = 1e18;
int n, x;
int a[N], b[N], p[N], q[N];

bool check(int mid) {
    int total = 0;
    for(int i=1; i<=n; i++) {
        int min_cost = INF;
        // Try all possible j (number of type A operations)
        for(int j=0; j<=mid/a[i]+1; j++) {
            if(j > mid/a[i]) continue;
            int remaining = mid - j*a[i];
            if(remaining < 0) continue;
            int k = remaining / b[i];  // number of type B operations
            int cost = j*p[i] + k*q[i];
            if(cost < min_cost) min_cost = cost;
        }
        // Also try all possible k (number of type B operations)
        for(int k=0; k<=mid/b[i]+1; k++) {
            if(k > mid/b[i]) continue;
            int remaining = mid - k*b[i];
            if(remaining < 0) continue;
            int j = remaining / a[i];  // number of type A operations
            int cost = j*p[i] + k*q[i];
            if(cost < min_cost) min_cost = cost;
        }
        if(min_cost == INF) return false;
        total += min_cost;
        if(total > x) return false;
    }
    return total <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    int l = 0, r = 1e18;
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}