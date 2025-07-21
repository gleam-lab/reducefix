#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Binary search to find the first index where x[i] >= l
        int left = 1, right = n;
        int start = n + 1; // If not found, means no element >= l
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) {
                start = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Binary search to find the last index where x[i] <= r
        left = 1, right = n;
        int end = 0; // If not found, means no element <= r
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] <= r) {
                end = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Check if there is an overlap
        if (start <= end)
            cout << a[end] - a[start - 1] << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}