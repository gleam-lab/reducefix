#include<bits/stdc++.h>
using namespace std;

long long n, x;
long long a[105], p[105], b[105], q[105];

bool isPossible(long long mid) {
    long long total = 0;
    for(int i = 1; i <= n; i++) {
        long long min_cost = LLONG_MAX;
        // Try all possible combinations of a and b items
        for(long long j = 0; j <= min(mid / a[i] + 1, b[i]); j++) {
            long long rem = mid - j * a[i];
            if(rem <= 0) {
                min_cost = min(min_cost, j * p[i]);
            } else {
                long long k = (rem + b[i] - 1) / b[i];  // ceiling division
                if(k <= q[i]) {
                    min_cost = min(min_cost, j * p[i] + k * q[i]);
                }
            }
        }
        for(long long j = 0; j <= min(mid / b[i] + 1, a[i]); j++) {
            long long rem = mid - j * b[i];
            if(rem <= 0) {
                min_cost = min(min_cost, j * q[i]);
            } else {
                long long k = (rem + a[i] - 1) / a[i];  // ceiling division
                if(k <= p[i]) {
                    min_cost = min(min_cost, j * q[i] + k * p[i]);
                }
            }
        }
        if(min_cost == LLONG_MAX) return false;
        total += min_cost;
        if(total > x) return false;
    }
    return total <= x;
}

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e18, ans = 0;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
        if(isPossible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}