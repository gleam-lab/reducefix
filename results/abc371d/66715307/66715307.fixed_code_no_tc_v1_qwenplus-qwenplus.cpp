#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;
int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Binary search to find the first index where x[i] >= l
        int left1 = 1, right1 = n;
        int lower_idx = n + 1;
        while (left1 <= right1) {
            int mid = (left1 + right1) / 2;
            if (x[mid] >= l) {
                lower_idx = mid;
                right1 = mid - 1;
            } else {
                left1 = mid + 1;
            }
        }

        // Binary search to find the last index where x[i] <= r
        int left2 = 1, right2 = n;
        int upper_idx = 0;
        while (left2 <= right2) {
            int mid = (left2 + right2 + 1) / 2;
            if (x[mid] <= r) {
                upper_idx = mid;
                left2 = mid + 1;
            } else {
                right2 = mid - 1;
            }
        }

        if (lower_idx > upper_idx || upper_idx == 0 || lower_idx > n) {
            cout << 0 << '\n';
        } else {
            cout << a[upper_idx] - a[lower_idx - 1] << '\n';
        }
    }

    return 0;
}