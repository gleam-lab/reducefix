#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n), p(n), b(n), q(n);
    
    for(long long i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto is_possible = [&](long long k) {
        long long total_cost = 0;
        for(long long i = 0; i < n; ++i) {
            long long min_cost = numeric_limits<long long>::max();
            // Try all possible number of type A candies from 0 to max needed to reach k
            for(long long j = 0; j <= b[i]; ++j) {
                long long remaining = k - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                    continue;
                }
                long long y = (remaining + b[i] - 1) / b[i]; // ceil division
                if(y <= q[i]) { // Check if we can afford the required B candies
                    min_cost = min(minn, j * p[i] + y * q[i]);
                }
            }
            for(long long j = 0; j <= a[i]; ++j) {
                long long remaining = k - j * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * q[i]);
                    continue;
                }
                long long y = (remaining + a[i] - 1) / a[i]; // ceil division
                if(y <= p[i]) { // Check if we can afford the required A candies
                    min_cost = min(min_cost, j * q[i] + y * p[i]);
                }
            }
            total_cost += min_cost;
            if(total_cost > x) break;
        }
        return total_cost <= x;
    };

    long long l = 0, r = 2e18, ans = 0;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(is_possible(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}