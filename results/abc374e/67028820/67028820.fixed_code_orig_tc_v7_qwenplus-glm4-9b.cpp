#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;
const ld EPS = 1e-9;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            int x = mid / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += temp * t;
        } else {
            int x = mid / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += temp * s;
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
        int mid = left + (right - left) / 2;
        if (canMake(mid)) left = mid + 1;
        else right = mid;
    }

    cout << left - 1;

    return 0;
}