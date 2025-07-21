#include<bits/stdc++.h>
using namespace std;

long long n, x, a[105], p[105], b[105], q[105];

bool isPossible(long long days) {
    long long total_cost = 0;
    for (int i = 1; i <= n; i++) {
        long long min_cost = LLONG_MAX;
        
        // Find optimal combination of a and b usage
        // We can use at most days/a[i] of a and days/b[i] of b
        long long max_a = min(days / a[i], b[i]);
        long long max_b = min(days / b[i], a[i]);
        
        // Check all possible a counts (0 to max_a)
        for (long long j = 0; j <= max_a; j++) {
            long long remaining_days = days - j * a[i];
            if (remaining_days < 0) remaining_days = 0;
            
            long long k = (remaining_days + b[i] - 1) / b[i]; // ceil division
            if (k > a[i]) continue; // can't use more than a[i] b's
            
            long long cost = j * p[i] + k * q[i];
            if (cost < min_cost) min_cost = cost;
        }
        
        // Check all possible b counts (0 to max_b)
        for (long long k = 0; k <= max_b; k++) {
            long long remaining_days = days - k * b[i];
            if (remaining_days < 0) remaining_days = 0;
            
            long long j = (remaining_days + a[i] - 1) / a[i]; // ceil division
            if (j > b[i]) continue; // can't use more than b[i] a's
            
            long long cost = k * q[i] + j * p[i];
            if (cost < min_cost) min_cost = cost;
        }
        
        if (min_cost == LLONG_MAX) return false; // can't satisfy this day requirement
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
    
    long long low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}