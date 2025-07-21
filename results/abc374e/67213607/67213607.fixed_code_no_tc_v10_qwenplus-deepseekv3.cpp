#include<bits/stdc++.h>
using namespace std;

long long n, x;
long long a[105], p[105], b[105], q[105];

bool isPossible(long long days) {
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        long long min_cost = LLONG_MAX;
        // Try all possible combinations of buying a and b
        // We limit the iterations to days+1 to avoid excessive computations
        for (long long buy_a = 0; buy_a <= min(days/a[i] + 1, b[i]); buy_a++) {
            long long remaining_days = days - buy_a * a[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, buy_a * p[i]);
                continue;
            }
            long long buy_b = remaining_days / b[i];
            if (buy_b > q[i]) buy_b = q[i];
            min_cost = min(min_cost, buy_a * p[i] + buy_b * q[i]);
            
            // Also check buy_b + 1 if it's within limit
            if (buy_b + 1 <= q[i]) {
                min_cost = min(min_cost, buy_a * p[i] + (buy_b + 1) * q[i]);
            }
        }
        
        for (long long buy_b = 0; buy_b <= min(days/b[i] + 1, q[i]); buy_b++) {
            long long remaining_days = days - buy_b * b[i];
            if (remaining_days < 0) {
                min_cost = min(min_cost, buy_b * q[i]);
                continue;
            }
            long long buy_a = remaining_days / a[i];
            if (buy_a > p[i]) buy_a = p[i];
            min_cost = min(min_cost, buy_b * q[i] + buy_a * p[i]);
            
            // Also check buy_a + 1 if it's within limit
            if (buy_a + 1 <= p[i]) {
                min_cost = min(min_cost, buy_b * q[i] + (buy_a + 1) * p[i]);
            }
        }
        
        total_cost += min_cost;
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    long long left = 0, right = 1e18, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}