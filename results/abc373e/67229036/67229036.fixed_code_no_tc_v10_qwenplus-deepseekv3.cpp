#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k;
int a[N], sorted_a[N], prefix[N];

bool is_possible(int candidate_votes, int x) {
    int total_votes = candidate_votes + x;
    int pos = upper_bound(sorted_a + 1, sorted_a + n + 1, total_votes) - sorted_a - 1;
    int rank = n - pos;
    if (rank < m) {
        return true;
    } else {
        int same_or_higher = (n - pos + 1);
        if (same_or_higher <= m) {
            return true;
        } else {
            int needed = 0;
            int start = n - m + 1;
            if (start <= pos) {
                needed = (total_votes + 1) * (pos - start + 1) - (prefix[pos] - prefix[start - 1]);
            }
            return (needed <= (k - x));
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int total_initial = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total_initial += a[i];
        sorted_a[i] = a[i];
    }
    sort(sorted_a + 1, sorted_a + n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + sorted_a[i];
    }
    int remaining = k - total_initial;
    for (int i = 1; i <= n; i++) {
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
        cout << (ans <= remaining ? ans : -1) << " ";
    }
    return 0;
}