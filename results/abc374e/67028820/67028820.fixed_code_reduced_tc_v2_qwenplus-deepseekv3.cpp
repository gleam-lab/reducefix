#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        ld s = (ld)p[i] / a[i];
        ld t = (ld)q[i] / b[i];

        if (s < t) {
            int cnt = temp / a[i];
            total_cost += cnt * p[i];
            temp -= cnt * a[i];
            total_cost += (int)ceil(temp * t);
        } else {
            int cnt = temp / b[i];
            total_cost += cnt * q[i];
            temp -= cnt * b[i];
            total_cost += (int)ceil(temp * s);
        }
    }
    return total_cost <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}