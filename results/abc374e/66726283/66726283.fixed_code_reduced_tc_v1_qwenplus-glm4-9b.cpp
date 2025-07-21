#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n, x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = INT_MAX;
        // Calculate cost with p[i] as weight
        for (int j = 0; j <= b[i]; j++) {
            int cost = (j * p[i] + q[i] * (mid - j * a[i] + b[i] - 1)) / b[i];
            c[i] = min(c[i], cost);
        }
        // Calculate cost with q[i] as weight
        for (int j = 0; j <= b[i]; j++) {
            int cost = (j * q[i] + p[i] * (mid - j * b[i] + a[i] - 1)) / a[i];
            c[i] = min(c[i], cost);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    return ans <= x;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}