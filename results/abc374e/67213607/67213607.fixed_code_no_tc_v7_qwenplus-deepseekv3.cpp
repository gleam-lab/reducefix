#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans;

long long calculate_cost(long long days) {
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        long long min_cost = LLONG_MAX;
        // Try all possible combinations of a and b usages
        // We limit the iterations to avoid excessive computation
        // The maximum needed is days / min(a[i], b[i]) + 1
        long long max_j = min(days / a[i] + 1, b[i] + 1);
        for (long long j = 0; j <= max_j; j++) {
            long long remaining_days = days - j * a[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, j * p[i]);
                continue;
            }
            long long k = remaining_days / b[i];
            if (k > q[i]) continue;  // Can't use more than q[i] b's
            long long cost = j * p[i] + k * q[i];
            min_cost = min(min_cost, cost);
        }
        max_j = min(days / b[i] + 1, a[i] + 1);
        for (long long j = 0; j <= max_j; j++) {
            long long remaining_days = days - j * b[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, j * q[i]);
                continue;
            }
            long long k = remaining_days / a[i];
            if (k > p[i]) continue;  // Can't use more than p[i] a's
            long long cost = j * q[i] + k * p[i];
            min_cost = min(min_cost, cost);
        }
        total_cost += min_cost;
    }
    return total_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    l = 0;
    r = 1e18;  // Sufficiently large upper bound
    ans = 0;
    
    while (l <= r) {
        mid = l + (r - l) / 2;
        long long current_cost = calculate_cost(mid);
        if (current_cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans;
    return 0;
}