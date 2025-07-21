#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = (p[i] * 1.0) / a[i], t = (q[i] * 1.0) / b[i];
        int cost_a = mid / a[i] * p[i];
        int remaining_a = mid % a[i];
        int cost_b = mid / b[i] * q[i];
        int remaining_b = mid % b[i];
        if (s < t) {
            total_cost += cost_a + remaining_a * t;
        } else {
            total_cost += cost_b + remaining_b * s;
        }
    }
    return ceil(total_cost) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canMake(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left;

    return 0;
}