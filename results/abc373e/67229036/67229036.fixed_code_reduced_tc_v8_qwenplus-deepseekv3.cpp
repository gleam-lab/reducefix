#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,a[N],b[N],c[N];

bool check(int i, int x) {
    int total = a[i] + x;
    int pos = upper_bound(b+1, b+n+1, total) - b;
    int cnt = n - pos + 1;
    if (cnt < m) return true;
    
    int left_votes = k - x;
    int needed = 0;
    int j = pos;
    int t = cnt - (m - 1);
    if (t <= 0) return true;
    needed = (total + 1) * t - (c[n] - c[n - t]);
    return needed <= left_votes;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    for (int i=1; i<=n; i++) {
        c[i] = c[i-1] + b[i];
    }
    for (int i=1; i<=n; i++) {
        int l = 0, r = k;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(i, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1 && ans <= k) {
            cout << ans << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}