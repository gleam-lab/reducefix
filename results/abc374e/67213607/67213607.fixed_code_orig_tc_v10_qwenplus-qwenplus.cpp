#include <bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, sum;

// Function to compute ceiling division
long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    l = 0;
    r = 1000000005; // upper bound on binary search

    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;

        for (int i = 1; i <= n; i++) {
            long long min_cost = 1e18;

            // Try fixing number of A used
            for (long long j = 0; j <= mid / a[i] + 1 && j <= 10000; j++) {
                long long needed = max(0LL, mid - j * a[i]);
                long long k = ceil_div(needed, b[i]);
                if (k > 1e6) continue; // Avoid overflow or unreasonable values
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }

            // Try fixing number of B used
            for (long long j = 0; j <= mid / b[i] + 1 && j <= 10000; j++) {
                long long needed = max(0LL, mid - j * b[i]);
                long long k = ceil_div(needed, a[i]);
                if (k > 1e6) continue;
                min_cost = min(min_cost, j * q[i] + k * p[i]);
            }

            sum += min_cost;
        }

        if (sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}