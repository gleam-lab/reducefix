#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans, minn, sum;

// Function to compute minimum cost for one item and given quantity
long long computeMinCost(long long quantity, long long a, long long p, long long b, long long q) {
    long long minCost = 2e18;
    // Try all possible numbers of type A items used to fulfill the quantity
    for (long long j = 0; j <= b && j * a <= quantity; ++j) {
        long long remaining = quantity - j * a;
        if (remaining <= 0) {
            minCost = min(minCost, j * p);
        } else {
            long long neededB = (remaining + b - 1) / b;
            minCost = min(minCost, j * p + neededB * q);
        }
    }
    // Try all possible numbers of type B items used to fulfill the quantity
    for (long long j = 0; j <= a && j * b <= quantity; ++j) {
        long long remaining = quantity - j * b;
        if (remaining <= 0) {
            minCost = min(minCost, j * q);
        } else {
            long long neededA = (remaining + a - 1) / a;
            minCost = min(minCost, j * q + neededA * p);
        }
    }
    return minCost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    l = 0;
    r = 1000000005;
    while (l <= r) {
        mid = (l + r) / 2;
        sum = 0;

        for (int i = 1; i <= n && sum <= x; ++i) {
            minn = computeMinCost(mid, a[i], p[i], b[i], q[i]);
            sum += minn;
        }

        if (sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}