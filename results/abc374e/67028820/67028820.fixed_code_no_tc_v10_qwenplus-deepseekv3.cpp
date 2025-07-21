#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        // Calculate how many full sets of a[i] we can buy
        int cnt_a = remaining / a[i];
        int cost_a = cnt_a * p[i];
        remaining -= cnt_a * a[i];
        // The remaining can be filled with b[i] items
        int cost_b = (remaining + b[i] - 1) / b[i] * q[i];
        
        // Similarly for the other option
        int cnt_b = mid / b[i];
        int cost_b_alt = cnt_b * q[i];
        remaining = mid - cnt_b * b[i];
        int cost_a_alt = (remaining + a[i] - 1) / a[i] * p[i];
        
        // Choose the cheaper option
        total_cost += min(cost_a + cost_b, cost_b_alt + cost_a_alt);
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