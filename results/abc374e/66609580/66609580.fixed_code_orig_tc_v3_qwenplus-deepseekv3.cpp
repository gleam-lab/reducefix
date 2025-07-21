#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110], b[110], p[110], q[110], x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long min_cost = LLONG_MAX;
        long long max_j = v / a[i] + 1;
        for (long long j = 0; j <= max_j; ++j) {
            long long remaining = v - j * a[i];
            if (remaining < 0) continue;
            long long k = remaining / b[i];
            if (remaining % b[i] != 0) ++k;
            long long cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
            if (min_cost == 0) break;
        }
        total += min_cost;
        if (total > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    long long l = 0, r = 1LL << 60;
    while (l < r) {
        long long mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}