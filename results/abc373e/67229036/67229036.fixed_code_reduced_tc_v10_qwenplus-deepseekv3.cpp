#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N];

bool check(int i, int x) {
    int total_votes = a[i] + x;
    int pos = upper_bound(b + 1, b + n + 1, total_votes) - b - 1;
    pos = n - pos;
    if (pos < m) {
        return true;
    }
    int threshold = b[n - m + 1];
    if (total_votes >= threshold) {
        return true;
    }
    int sum = 0;
    int cnt = n - m;
    if (cnt > 0) {
        sum = c[n] - c[n - cnt] - max(total_votes, b[n - cnt]);
    }
    return (a[i] + x) * cnt - sum <= k - x;
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
            if (check(i, mid)) {
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