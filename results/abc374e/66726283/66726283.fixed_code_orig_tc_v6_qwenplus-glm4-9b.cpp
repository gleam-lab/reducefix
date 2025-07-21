#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n;
int x;
int a[N], p[N], b[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        c[i] = (mid / b[i]) * p[i] + (mid % b[i]) * q[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += c[i];
    }
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e15;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l;
    return 0;
}