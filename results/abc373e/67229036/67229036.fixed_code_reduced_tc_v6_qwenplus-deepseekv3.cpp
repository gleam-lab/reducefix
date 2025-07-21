#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m, k, a[N], b[N], c[N];

bool check(int i, int x) {
    int total = a[i] + x;
    int pos = upper_bound(b + 1, b + n + 1, total) - b;
    pos = n + 1 - pos;
    if (pos < m) return true;
    
    int worst_case = (n - pos) + 1;
    if (worst_case > m) return false;
    
    int sum_extra = 0;
    int start = upper_bound(b + 1, b + n + 1, total) - b;
    int end = n;
    if (start <= end) {
        sum_extra = (c[n] - c[start - 1]) - total * (end - start + 1);
    }
    return (sum_extra + x) <= k;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    for(int i = 1; i <= n; ++i) {
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