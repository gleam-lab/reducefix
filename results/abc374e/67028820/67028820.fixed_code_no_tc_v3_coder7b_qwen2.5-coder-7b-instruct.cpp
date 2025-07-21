#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ld s = (ld)p[i] / a[i];
        ld t = (ld)q[i] / b[i];

        if (s < t) {
            total_cost += ((mid + a[i] - 1) / a[i]) * p[i]; // Calculate cost for machine S_i
        } else {
            total_cost += ((mid + b[i] - 1) / b[i]) * q[i]; // Calculate cost for machine T_i
        }
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