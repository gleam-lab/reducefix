#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_p = p[i];
        int cost_q = q[i];
        int time_a = a[i];
        int time_b = b[i];
        
        // Calculate full cycles for each option
        int full_a = remaining / time_a;
        int cost_a = full_a * cost_p;
        int rem_a = remaining - full_a * time_a;
        
        int full_b = remaining / time_b;
        int cost_b = full_b * cost_q;
        int rem_b = remaining - full_b * time_b;
        
        // Calculate which option is better for the remaining time
        int option1 = cost_a + (rem_a > 0 ? min(cost_p, (rem_a + time_b - 1) / time_b * cost_q) : 0);
        int option2 = cost_b + (rem_b > 0 ? min(cost_q, (rem_b + time_a - 1) / time_a * cost_p) : 0);
        
        total_cost += min(option1, option2);
        
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}