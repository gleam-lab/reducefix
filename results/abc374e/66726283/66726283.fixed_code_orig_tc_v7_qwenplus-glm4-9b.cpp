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
        for (int j = 0; j <= b[i]; j++) {
            int cost1 = j * p[i];
            int cost2 = (mid - j * a[i]) * q[i];
            int totalCost = cost1 + cost2;
            c[i] = min(c[i], totalCost);
        }
        for (int j = 0; j <= a[i]; j++) {
            int cost1 = j * q[i];
            int cost2 = (mid - j * b[i]) * p[i];
            int totalCost = cost1 + cost2;
            c[i] = min(c[i], totalCost);
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
    cin >> n;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}