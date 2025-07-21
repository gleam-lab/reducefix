#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N];

bool check(int idx, int x) {
    int new_vote = a[idx] + x;
    int pos = upper_bound(b + 1, b + n + 1, new_vote) - b;
    int cnt = n - pos + 1;
    if (cnt >= m) return false;
    
    int needed = 0;
    int start = pos - (m - cnt);
    if (start <= 0) return true;
    for (int i = start; i < pos; ++i) {
        needed += max(0LL, new_vote + 1 - b[i]);
    }
    return needed <= (k - x);
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
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = k - (total - a[i]);
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
        cout << ans << " ";
    }
    return 0;
}