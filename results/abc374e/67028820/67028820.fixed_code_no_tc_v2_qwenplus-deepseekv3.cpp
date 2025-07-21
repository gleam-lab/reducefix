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
        ld cost_a = p[i] / (ld)a[i];
        ld cost_b = q[i] / (ld)b[i];
        
        // Calculate cost for both options and choose the cheaper one
        ld option1 = (remaining / a[i]) * p[i] + (remaining % a[i]) * cost_b;
        ld option2 = (remaining / b[i]) * q[i] + (remaining % b[i]) * cost_a;
        total_cost += min(option1, option2);
        
        if (total_cost > x) return false;  // Early exit if budget exceeded
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;  // Increased upper bound
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