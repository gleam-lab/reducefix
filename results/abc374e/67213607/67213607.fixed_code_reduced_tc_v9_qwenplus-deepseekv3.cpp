#include<bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105];

long long calculate_cost(long long mid) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        long long min_cost = LLONG_MAX;
        // Try all possible combinations of a and b items
        for (long long j = 0; j <= mid/a[i] + 1; j++) {
            long long remaining = mid - j * a[i];
            if (remaining < 0) {
                min_cost = min(min_cost, j * p[i]);
                continue;
            }
            long long k = remaining / b[i];
            if (remaining % b[i] != 0) k++;
            if (k < 0) k = 0;
            min_cost = min(min_cost, j * p[i] + k * q[i]);
        }
        for (long long j = 0; j <= mid/b[i] + 1; j++) {
            long long remaining = mid - j * b[i];
            if (remaining < 0) {
                min_cost = min(min_cost, j * q[i]);
                continue;
            }
            long long k = remaining / a[i];
            if (remaining % a[i] != 0) k++;
            if (k < 0) k = 0;
            min_cost = min(min_cost, j * q[i] + k * p[i]);
        }
        total += min_cost;
        if (total > x) break; // Early termination if exceeded
    }
    return total;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long cost = calculate_cost(mid);
        if (cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}