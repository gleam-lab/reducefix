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
            if (j * a[i] <= mid) {
                c[i] = min(c[i], j * p[i] + q[i] * ((mid - j * a[i]) / a[i]));
            }
            if ((mid - j * a[i]) % a[i] != 0) {
                c[i] = min(c[i], (j + 1) * p[i] + q[i] * (((mid - j * a[i]) / a[i]) + 1));
            }
        }
        for (int j = 0; j <= b[i]; j++) {
            if (j * b[i] <= mid) {
                c[i] = min(c[i], j * q[i] + p[i] * ((mid - j * b[i]) / b[i]));
            }
            if ((mid - j * b[i]) % b[i] != 0) {
                c[i] = min(c[i], (j + 1) * q[i] + p[i] * (((mid - j * b[i]) / b[i]) + 1));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    return ans <= x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e9; // Adjust upper bound based on problem constraints
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l - 1 << endl; // Return the largest value that satisfies the condition
    return 0;
}