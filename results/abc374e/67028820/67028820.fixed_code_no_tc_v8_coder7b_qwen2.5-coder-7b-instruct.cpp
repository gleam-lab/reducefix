#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            int x = min(mid / a[i], q[i] / t);
            total_cost += x * p[i];
            temp -= x * a[i];
            if (temp > 0) {
                int y = min(temp / b[i], s);
                total_cost += y * q[i];
                temp -= y * b[i];
            }
        } else {
            int x = min(mid / b[i], p[i] / s);
            total_cost += x * q[i];
            temp -= x * b[i];
            if (temp > 0) {
                int y = min(temp / a[i], t);
                total_cost += y * p[i];
                temp -= y * a[i];
            }
        }
    }

    return ceil(total_cost) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
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