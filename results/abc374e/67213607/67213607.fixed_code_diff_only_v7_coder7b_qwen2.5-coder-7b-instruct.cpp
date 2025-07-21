#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = 2e9;

int n, x;
int a[MAXN], p[MAXN], b[MAXN], q[MAXN];

bool check(int mid) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int minn = INF;
        for (int j = 0; j <= b[i]; ++j) {
            if ((mid - j * a[i]) >= 0) {
                minn = min(minn, j * p[i]);
                if ((mid - j * a[i]) % b[i] == 0) {
                    minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
                } else {
                    minn = min(minn, j * p[i] + (mid - j * a[i]) / b[i] + 1) * q[i]);
                }
            }
        }
        for (int j = 0; j <= a[i]; ++j) {
            if ((mid - j * b[i]) >= 0) {
                minn = min(minn, j * q[i]);
                if ((mid - j * b[i]) % a[i] == 0) {
                    minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
                } else {
                    minn = min(minn, j * q[i] + (mid - j * b[i]) / a[i] + 1) * p[i]);
                }
            }
        }
        sum += minn;
    }
    return sum <= x;
}

int binary_search() {
    int l = 0, r = 1000000005;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    cout << binary_search();
    return 0;
}