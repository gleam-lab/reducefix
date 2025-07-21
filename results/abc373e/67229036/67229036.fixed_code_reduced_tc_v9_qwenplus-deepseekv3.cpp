#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N];

bool check(int i, int x) {
    int target = a[i] + x;
    int idx = upper_bound(b + 1, b + n + 1, target) - b;
    int cnt = n - idx + 1;
    if (cnt >= m) return false;
    int max_possible = (m - 1) - cnt;
    if (max_possible < 0) return true;
    int sum_needed = 0;
    int start = idx - max_possible;
    if (start <= 0) return false;
    sum_needed = target * max_possible - (c[idx - 1] - c[start - 1]);
    return sum_needed <= (k - x);
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