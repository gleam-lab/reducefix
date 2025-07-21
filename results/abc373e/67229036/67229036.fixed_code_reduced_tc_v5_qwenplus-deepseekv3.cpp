#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], c[N];

bool check(int x, int y) {
    int new_votes = x + y;
    int pos = upper_bound(b + 1, b + n + 1, new_votes) - b;
    int cnt = n - pos + 1;
    if (cnt < m) {
        return true;
    }
    int required = 0;
    int s = pos;
    int e = n;
    int need = cnt - (m - 1);
    if (need <= 0) {
        return true;
    }
    int sum = 0;
    int start_pos = n - need + 1;
    sum = c[n] - c[start_pos - 1] - (new_votes + 1) * need;
    if (sum + y <= k) {
        return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    int remaining = k - total;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = remaining + 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(a[i], mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1 && ans <= remaining) {
            cout << ans << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}