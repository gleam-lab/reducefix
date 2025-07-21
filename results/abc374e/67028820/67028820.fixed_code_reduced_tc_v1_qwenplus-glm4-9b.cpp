#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            total_cost += (mid / a[i]) * p[i];
            temp -= (mid / a[i]) * a[i];
            total_cost += temp * t;
        } else {
            total_cost += (mid / b[i]) * q[i];
            temp -= (mid / b[i]) * b[i];
            total_cost += temp * s;
        }
    }

    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}