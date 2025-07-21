#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
const int INF=1e18;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for(int i=1; i<=n; i++) {
        c[i] = INF;
        // Try all possible combinations of a and b
        for(int j=0; j*a[i] <= mid; j++) {
            int remaining = mid - j*a[i];
            if(remaining < 0) continue;
            int k = remaining / b[i];
            c[i] = min(c[i], j*p[i] + k*q[i]);
        }
        for(int j=0; j*b[i] <= mid; j++) {
            int remaining = mid - j*b[i];
            if(remaining < 0) continue;
            int k = remaining / a[i];
            c[i] = min(c[i], j*q[i] + k*p[i]);
        }
    }
    int total = 0;
    for(int i=1; i<=n; i++) {
        if(c[i] == INF) return false;
        total += c[i];
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