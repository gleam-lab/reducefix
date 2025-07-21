#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        ld cost_a = p[i] / (ld)a[i];  // cost per unit when buying a bundles
        ld cost_b = q[i] / (ld)b[i];  // cost per unit when buying b bundles
        
        if (cost_a < cost_b) {
            // Buy as many a bundles as possible
            int cnt = remaining / a[i];
            total_cost += cnt * p[i];
            remaining -= cnt * a[i];
            
            // Buy remaining with cheaper option
            ld cost_remaining = min((ld)p[i], remaining * cost_a);
            if (remaining > 0) {
                cost_remaining = min(cost_remaining, 
                                   min((ld)q[i], remaining * cost_b));
            }
            total_cost += cost_remaining;
        } else {
            // Buy as many b bundles as possible
            int cnt = remaining / b[i];
            total_cost += cnt * q[i];
            remaining -= cnt * b[i];
            
            // Buy remaining with cheaper option
            ld cost_remaining = min((ld)q[i], remaining * cost_b);
            if (remaining > 0) {
                cost_remaining = min(cost_remaining, 
                                   min((ld)p[i], remaining * cost_a));
            }
            total_cost += cost_remaining;
        }
        
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = x * (*max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end()));
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}