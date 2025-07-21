#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], c[N];

bool check(int target, int x) {
    int total = target + x;
    int pos = upper_bound(b + 1, b + n + 1, total) - b;
    int cnt = n - pos + 1;
    if (cnt < m) return true;
    
    int sum_required = 0;
    int start = pos;
    int end = n;
    if (start <= end) {
        int needed = cnt - (m - 1);
        int min_votes = b[start];
        if (total >= min_votes) {
            sum_required = (total + 1) * needed - (c[end] - c[end - needed]);
        } else {
            sum_required = (total + 1) * needed - (c[start + needed - 1] - c[start - 1]);
        }
    }
    return (sum_required <= (k - x));
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for(int i = 1; i <= n; i++) {
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
        if (ans != -1 && ans <= k - (sum - a[i])) {
            cout << ans << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}