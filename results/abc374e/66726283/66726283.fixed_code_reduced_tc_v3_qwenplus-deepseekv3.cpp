#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for(int i=1; i<=n; i++) {
        c[i] = LLONG_MAX;
        // Case 1: Use j type A operations and the rest type B
        for(int j=0; j<=min(mid/a[i], b[i]); j++) {
            int rem = mid - j*a[i];
            if(rem < 0) continue;
            int k = (rem + b[i] - 1) / b[i];
            c[i] = min(c[i], j*p[i] + k*q[i]);
        }
        // Case 2: Use j type B operations and the rest type A
        for(int j=0; j<=min(mid/b[i], a[i]); j++) {
            int rem = mid - j*b[i];
            if(rem < 0) continue;
            int k = (rem + a[i] - 1) / a[i];
            c[i] = min(c[i], j*q[i] + k*p[i]);
        }
    }
    int total = 0;
    for(int i=1; i<=n; i++) {
        total += c[i];
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
        int mid = l + (r - l) / 2;
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