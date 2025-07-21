#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;
int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        p[i] = x[i];  // Fix: We need to build prefix sum on x[], not p[]
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        int left = 1, right = n, start = -1, end = -1;

        // Binary search to find first index where x[i] >= l
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) {
                start = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Binary search to find last index where x[i] <= r
        left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] <= r) {
                end = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (start == -1 || end == -1 || start > end) {
            cout << 0 << endl;
        } else {
            cout << a[end] - a[start - 1] << endl;
        }
    }

    return 0;
}