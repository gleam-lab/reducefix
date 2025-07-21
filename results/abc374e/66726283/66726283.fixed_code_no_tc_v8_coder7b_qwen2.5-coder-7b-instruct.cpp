#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 105;

int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];

bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        c[i] = INT_MAX;
        for (int j = 0; j <= b[i]; ++j) {
            c[i] = min(c[i], j * p[i] + q[i] * ((mid - j * a[i] + b[i] - 1) / b[i]));
        }
        for (int j = 0; j <= b[i]; ++j) {
            c[i] = min(c[i], j * q[i] + p[i] * ((mid - j * b[i] + a[i] - 1) / a[i]));
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

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 1, r = 1e18; // Adjust upper bound based on constraints
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << r << endl; // Correct output should be 'r' instead of 'l'
    return 0;
}