#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], sum[N];

bool is_possible(int candidate_votes, int x) {
    int total_used = x;
    int idx = upper_bound(b + 1, b + n + 1, candidate_votes + x) - b;
    int count = n - idx + 1;
    if (count >= m) return false;
    int needed_votes = 0;
    if (idx <= n) {
        needed_votes = (sum[n] - sum[idx - 1]) - (candidate_votes + x) * (n - idx + 1);
    }
    return total_used + needed_votes <= k;
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
        sum[i] = sum[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        int low = 0, high = k, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (is_possible(a[i], mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " ";
    }
    return 0;
}