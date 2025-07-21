#include<bits/stdc++.h>
using namespace std;
long long n, x, a[105], p[105], b[105], q[105], l, r, mid, ans;

long long compute_cost(long long mid, long long a, long long p, long long b, long long q) {
    long long min_cost = LLONG_MAX;
    long long max_j = min(mid / a, b) + 2;
    for (long long j = 0; j <= max_j; ++j) {
        if (j * a > mid) continue;
        long long remaining = mid - j * a;
        long long k = remaining / b;
        if (remaining < 0) k = -1;
        if (k < 0) {
            min_cost = min(min_cost, j * p);
        } else {
            if (remaining % b == 0) {
                min_cost = min(min_cost, j * p + k * q);
            } else {
                min_cost = min(min_cost, j * p + (k + 1) * q);
            }
        }
    }
    max_j = min(mid / b, a) + 2;
    for (long long j = 0; j <= max_j; ++j) {
        if (j * b > mid) continue;
        long long remaining = mid - j * b;
        long long k = remaining / a;
        if (remaining < 0) k = -1;
        if (k < 0) {
            min_cost = min(min_cost, j * q);
        } else {
            if (remaining % a == 0) {
                min_cost = min(min_cost, j * q + k * p);
            } else {
                min_cost = min(min_cost, j * q + (k + 1) * p);
            }
        }
    }
    return min_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    l = 0;
    r = 1e18;
    ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        long long total_cost = 0;
        bool feasible = true;
        for (int i = 1; i <= n; i++) {
            long long cost = compute_cost(mid, a[i], p[i], b[i], q[i]);
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}