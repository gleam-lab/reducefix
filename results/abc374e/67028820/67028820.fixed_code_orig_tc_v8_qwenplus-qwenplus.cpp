#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Try both options: use a[i] first or b[i] first, choose the cheaper one
        ld cost1 = (mid / a[i]) * p[i] + (ld)(mid % a[i]) * ((ld)p[i] / a[i]);
        ld cost2 = (mid / b[i]) * q[i] + (ld)(mid % b[i]) * ((ld)q[i] / b[i]);
        total_cost += min(cost1, cost2);
    }

    return (int)(ceil(total_cost)) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}