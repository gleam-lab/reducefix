#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], prefix[N];

bool check(int candidate_votes, int x, int total_remaining) {
    int new_votes = candidate_votes + x;
    int pos = upper_bound(b + 1, b + n + 1, new_votes) - b - 1;
    int higher = n - pos;
    if (higher >= m) return false;
    int needed = 0;
    int start = n - m + 1;
    if (start <= 0) start = 1;
    for (int i = start; i <= n; ++i) {
        if (b[i] >= new_votes) {
            needed += (b[i] - new_votes + 1);
        }
    }
    return (needed <= total_remaining - x);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        total += a[i];
        b[i] = a[i];
    }
    int remaining = k - total;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + b[i];
    }
    for (int i = 1; i <= n; ++i) {
        int low = 0, high = remaining, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(a[i], mid, remaining)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << ' ';
    }
    return 0;
}