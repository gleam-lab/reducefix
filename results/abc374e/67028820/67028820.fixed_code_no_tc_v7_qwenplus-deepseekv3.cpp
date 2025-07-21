#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int remaining = mid;
        int cost_a = (remaining / a[i]) * p[i];
        int cost_b = (remaining / b[i]) * q[i];
        
        if (cost_a < cost_b) {
            total_cost += cost_b;
            remaining %= b[i];
            total_cost += (remaining * p[i] + a[i] - 1) / a[i];
        } else {
            total_cost += cost_a;
            remaining %= a[i];
            total_cost += (remaining * q[i] + b[i] - 1) / b[i];
        }
        
        if (total_cost > x) return false;
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = x * (*max_element(a.begin(), a.end()));
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