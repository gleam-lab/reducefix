#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
long long a[105], p[105], b[105], q[105];

// Returns true if we can prepare 'target' meals within budget x
bool isPossible(long long target) {
    long long totalCost = 0;
    for (int i = 1; i <= n; ++i) {
        long long minCost = 1e18;
        // Try up to a[i] items of type A
        for (int j = 0; j <= a[i]; ++j) {
            long long remaining = max(0LL, target - j * a[i]);
            long long k = (remaining + b[i] - 1) / b[i]; // ceil division
            if (k <= b[i])
                minCost = min(minCost, 1LL * j * p[i] + k * q[i]);
        }
        // Try up to b[i] items of type B
        for (int j = 0; j <= b[i]; ++j) {
            long long remaining = max(0LL, target - j * b[i]);
            long long k = (remaining + a[i] - 1) / a[i];
            if (k <= a[i])
                minCost = min(minCost, 1LL * j * q[i] + k * p[i]);
        }
        totalCost += minCost;
        if (totalCost > x)
            return false;
    }
    return totalCost <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    long long l = 0, r = 1e14, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (isPossible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}