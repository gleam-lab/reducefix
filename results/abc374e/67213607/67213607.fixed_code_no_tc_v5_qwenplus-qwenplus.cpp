#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long n, x;
long long a[MAXN], p[MAXN], b[MAXN], q[MAXN];

// Function to compute the minimum cost for one item type
long long minCost(long long target, long long amountA, long long priceA, long long amountB, long long priceB) {
    long long min_cost = LLONG_MAX;

    // Try all possible purchases of item A (up to what's feasible with target)
    for (long long j = 0; j <= amountA && j * amountB <= target; j++) {
        long long remaining = target - j * amountB;
        long long neededB = (remaining + amountA - 1) / amountA; // ceil division
        if (neededB <= amountB) {
            long long totalCost = j * priceB + neededB * priceA;
            min_cost = min(min_cost, totalCost);
        }
    }

    // Try all possible purchases of item B (up to what's feasible with target)
    for (long long j = 0; j <= amountB && j * amountA <= target; j++) {
        long long remaining = target - j * amountA;
        long long neededA = (remaining + amountB - 1) / amountB; // ceil division
        if (neededA <= amountA) {
            long long totalCost = j * priceA + neededA * priceB;
            min_cost = min(min_cost, totalCost);
        }
    }

    return min_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e18; // Extended range due to high combinations
    long long ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long total_cost = 0;

        for (int i = 1; i <= n; ++i) {
            total_cost += minCost(mid, a[i], p[i], b[i], q[i]);
            if (total_cost > x) break; // Early exit if budget exceeded
        }

        if (total_cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}