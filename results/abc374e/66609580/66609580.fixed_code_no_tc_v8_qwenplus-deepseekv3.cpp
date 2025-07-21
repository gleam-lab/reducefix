#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110],b[110],p[110],q[110],x;

inline bool check(long long v) {
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        long long max_items = 0;
        long long max_a = v / a[i];
        long long max_b = v / b[i];
        
        // Find optimal combination of a and b items
        long long optimal = 0;
        long long min_cost = LLONG_MAX;
        
        // We need to check all possible combinations of a and b items
        // but we can limit the search to reasonable bounds
        long long max_try = min(max_a, (x / p[i]) + 1);
        for (long long j = 0; j <= max_try; j++) {
            long long remaining = v - j * a[i];
            if (remaining < 0) continue;
            long long k = remaining / b[i];
            long long cost = j * p[i] + k * q[i];
            if (cost < min_cost) {
                min_cost = cost;
                optimal = j + k;
            }
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long l = 0, r = 1e18;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}