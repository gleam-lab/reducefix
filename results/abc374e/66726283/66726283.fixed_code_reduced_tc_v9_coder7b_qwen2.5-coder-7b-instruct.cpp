#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;

int n;
int x;
int a[N], b[N], p[N], q[N];
int c[N];

bool check(int mid) {
    memset(c, INT_MAX, sizeof(c));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= b[i]; ++j) {
            if (j * a[i] + (mid - j) / b[i] >= 0 && j * a[i] + (mid - j) % b[i] == 0) {
                c[i] = min(c[i], j * p[i] + q[i] * ((mid - j) / b[i]));
            }
        }
        for (int j = 0; j <= b[i]; ++j) {
            if (j * b[i] + (mid - j) / a[i] >= 0 && j * b[i] + (mid - j) % a[i] == 0) {
                c[i] = min(c[i], j * q[i] + p[i] * ((mid - j) / a[i]));
            }
        }
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

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e18;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1 << endl;
    return 0;
}