#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], c[N];

bool check(int x, int y) {
    int total = x + y;
    int pos = upper_bound(b + 1, b + n + 1, total) - b - 1;
    if (n - pos >= m) return false;
    int needed = 0;
    int start = n - m + 1;
    if (start <= 0) return true;
    needed = total * (start - 1) - c[start - 1];
    needed += max(0LL, (total - b[start]) * (n - start + 1) - (c[n] - c[start - 1]));
    return needed <= k - y;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 0, r = k, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(a[i], mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }
    return 0;
}