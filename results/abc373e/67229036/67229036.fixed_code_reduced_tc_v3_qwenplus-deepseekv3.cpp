#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N];

bool check(int i, int x) {
    int total = a[i] + x;
    int pos = upper_bound(b + 1, b + n + 1, total) - b;
    int cnt = n + 1 - pos;
    if (cnt < m) return true;
    
    int sum = 0;
    int start = n - m + 1;
    if (start < pos) {
        sum = c[n] - c[start - 1] - (a[i] + x) * (n - start + 1);
    } else {
        sum = c[n] - c[pos - 1] - (a[i] + x) * (n - pos + 1);
    }
    return (sum <= k - x);
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
        int low = 0, high = k, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(i, mid)) {
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