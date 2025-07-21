#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], sorted[N], prefix[N];

bool is_possible(int candidate_votes, int x) {
    int total = candidate_votes + x;
    int pos = upper_bound(sorted + 1, sorted + n + 1, total) - sorted;
    int count = n - pos + 1;
    if (count >= m) return false;
    int needed = 0;
    if (pos <= n - (m - 1)) {
        needed = (total + 1) * (n - (m - 1) - pos + 1) - (prefix[n - (m - 1)] - prefix[pos - 1]);
    }
    return needed <= (k - x);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    int remaining = k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        remaining -= a[i];
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + sorted[i];
    }
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = remaining;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (is_possible(a[i], mid)) {
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