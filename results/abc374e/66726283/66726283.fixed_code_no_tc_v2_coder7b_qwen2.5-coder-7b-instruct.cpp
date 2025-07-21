#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;

int n;
int x;
int a[N], b[N], p[N], q[N];
int c[N];

bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = INT_MAX;
        for (int j = 0; j <= mid / a[i]; j++) {
            if (j * a[i] > mid) break;
            c[i] = min(c[i], j * p[i] + (mid - j * a[i]) * q[i] / b[i]);
        }
        for (int j = 0; j <= mid / b[i]; j++) {
            if (j * b[i] > mid) break;
            c[i] = min(c[i], j * q[i] + (mid - j * b[i]) * p[i] / a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    if (ans > x) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 0, r = 1e9; // Adjusted upper bound based on constraints
    while (l < r) {
        int mid = (l + r + 1) / 2; // Changed to mid = (l + r + 1) / 2 for correct binary search
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}